find_package(Git REQUIRED)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
set(SKIP_INSTALL_ALL TRUE)
set(ENABLE_BZIP2 OFF)
set(ENABLE_LZMA OFF)

# rapidxml Library
add_library(rapidxml INTERFACE)
target_include_directories(rapidxml INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/rapidxml)

# zlib Library
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/zlib" "${CMAKE_CURRENT_BINARY_DIR}/zlib" EXCLUDE_FROM_ALL)

set(ZLIB_LIB_INSTALL_PATH "${CMAKE_CURRENT_BINARY_DIR}/zlib/install")
add_custom_target(zlib_copy_static ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory "${ZLIB_LIB_INSTALL_PATH}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:zlibstatic>" "${ZLIB_LIB_INSTALL_PATH}/zlibstatic.lib"

    DEPENDS zlibstatic
    VERBATIM
)
# prepare for find_package(ZLIB REQUIRED) in other thirdparty libs
set(ZLIB_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/zlib")
# set(ZLIB_INCLUDE_DIR ${ZLIB_ROOT})
set(ZLIB_LIBRARY "${ZLIB_LIB_INSTALL_PATH}/zlibstatic.lib")

find_package(ZLIB REQUIRED)
if(TARGET ZLIB::ZLIB)
    get_target_property(ZLIB_INCLUDE_DIRS zlibstatic INTERFACE_INCLUDE_DIRECTORIES)
    # set(ZLIB_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/zlib" "${CMAKE_CURRENT_BINARY_DIR}/zlib")
    target_include_directories(ZLIB::ZLIB INTERFACE ${ZLIB_INCLUDE_DIRS})
    add_dependencies(ZLIB::ZLIB zlib_copy_static)
endif()


# libpng Library
set(PNG_TESTS OFF)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libpng EXCLUDE_FROM_ALL)

# libzip Library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libzip EXCLUDE_FROM_ALL)

# cxxopts Library
add_library(cxxopts INTERFACE)
target_include_directories(cxxopts INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/cxxopts/include)

if(SHADY_ENABLE_MODULE)
    # libcurl Library
    set(CURL_USE_SCHANNEL ON)
    set(CURL_USE_LIBSSH2 OFF)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/curl EXCLUDE_FROM_ALL)

    # nlohmann JSON Library
    add_library(json INTERFACE)
    target_include_directories(json INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/json/include)

    # Lua Library
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lua-cmake EXCLUDE_FROM_ALL)
    set(LUABRIDGE_TESTING OFF)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/LuaBridge EXCLUDE_FROM_ALL)

    # SokuLib Library
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SokuLib EXCLUDE_FROM_ALL)
endif()

# if(SHADY_ENABLE_TEST)
#     # gtest Library
#     add_git_module(googletest https://github.com/google/googletest release-1.11.0)
#     add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googletest EXCLUDE_FROM_ALL)

#     # benchmark Library
#     add_git_module(benchmark https://github.com/google/benchmark v1.6.0)
#     add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/benchmark EXCLUDE_FROM_ALL)
# endif()
