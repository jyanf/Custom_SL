cmake_minimum_required(VERSION 3.16)
cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0091 NEW)

string(TIMESTAMP SHADY_VER_DAY "%m%d" UTC)
string(TIMESTAMP SHADY_VER_YEAR "%Y" UTC)

project(shady-packer
	VERSION 2.7.${SHADY_VER_YEAR}.${SHADY_VER_DAY}
	DESCRIPTION "Tools for a specific fighting game.")
set(SHADY_VERSION ${PROJECT_VERSION})
string(REPLACE . , SHADY_VERSION_COMMA ${SHADY_VERSION})

string(TIMESTAMP SL_VER_DATE "%y%m%d" UTC)
set(SL_IVERSION 2.9-${SL_VER_DATE})
set(SL_VERSION 2.9.1)
string(REPLACE . , SL_VERSION_COMMA ${SL_VERSION},0)
string(REPLACE . , SL_IVERSION_COMMA 2.9,${SHADY_VER_DAY},${SHADY_VER_YEAR})

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
# generate pdb file for release build (https://stackoverflow.com/a/31264946)
SET(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")

set(SHADY_ENABLE_EXECUTABLE TRUE CACHE BOOL "Enable executable building")
set(SHADY_ENABLE_TEST FALSE CACHE BOOL "Enable test building")
set(SHADY_ENABLE_MODULE TRUE CACHE BOOL "Enable module building")
if(SHADY_ENABLE_MODULE AND (NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4))
	set(SHADY_ENABLE_MODULE FALSE)
	message(WARNING "Skipping Shady Modules: Can only build on Windows 32bits")
endif()

# Dependencies
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

# Shady *Core*
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/Core)
if(SHADY_ENABLE_EXECUTABLE)
	# Shady *Cli*
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/Cli)
	# Shady *Dnd*
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/Dnd)
endif()

# Shady *Loader*
if(SHADY_ENABLE_MODULE)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/Loader)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/Lua)
endif()

# Shady *Test*
# if(SHADY_ENABLE_TEST)
# 	enable_testing()
# 	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/Test)
# endif()
