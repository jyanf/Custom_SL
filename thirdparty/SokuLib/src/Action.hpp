//
// Created by PinkySmile on 12/05/2021.
//

#ifndef SOKULIB_ACTION_HPP
#define SOKULIB_ACTION_HPP

namespace SokuLib
{
	enum Action : unsigned short {
		/*   0 */ ACTION_IDLE,
		/*   1 */ ACTION_CROUCHING,
		/*   2 */ ACTION_CROUCHED,
		/*   3 */ ACTION_STANDING_UP,
		/*   4 */ ACTION_WALK_FORWARD,
		/*   5 */ ACTION_WALK_BACKWARD,
		/*   6 */ ACTION_NEUTRAL_JUMP,
		/*   7 */ ACTION_FORWARD_JUMP,
		/*   8 */ ACTION_BACKWARD_JUMP,
		/*   9 */ ACTION_FALLING,
		/*  10 */ ACTION_LANDING,
		/*  50 */ ACTION_STAND_GROUND_HIT_SMALL_HITSTUN = 50,
		/*  51 */ ACTION_STAND_GROUND_HIT_MEDIUM_HITSTUN,
		/*  52 */ ACTION_STAND_GROUND_HIT_BIG_HITSTUN,
		/*  53 */ ACTION_STAND_GROUND_HIT_HUGE_HITSTUN,
		/*  56 */ ACTION_STAND_GROUND_HIT_SMALL_HITSTUN_2 = 56,
		/*  57 */ ACTION_STAND_GROUND_HIT_MEDIUM_HITSTUN_2,
		/*  58 */ ACTION_STAND_GROUND_HIT_BIG_HITSTUN_2,
		/*  62 */ ACTION_CROUCH_GROUND_HIT_SMALL_HITSTUN = 62,
		/*  63 */ ACTION_CROUCH_GROUND_HIT_MEDIUM_HITSTUN,
		/*  64 */ ACTION_CROUCH_GROUND_HIT_BIG_HITSTUN,
		/*  70 */ ACTION_AIR_HIT_SMALL_HITSTUN = 70,
		/*  71 */ ACTION_AIR_HIT_MEDIUM_HITSTUN,
		/*  72 */ ACTION_AIR_HIT_BIG_HITSTUN,
		/*  73 */ ACTION_AIR_HIT_DIRECT_KNOCKDOWN,
		/*  74 */ ACTION_AIR_HIT_CAN_WALL_SLAM,
		/*  75 */ ACTION_AIR_HIT_BIG_HITSTUN4,
		/*  76 */ ACTION_AIR_HIT_WALL_SLAMMED,
		/*  77 */ ACTION_AIR_HIT_HUGE_HITSTUN,
		/*  78 */ ACTION_AIR_HIT_WALL_SLAMMED2,
		/*  88 */ ACTION_AIR_HIT_WILL_GROUND_SLAM = 88,
		/*  89 */ ACTION_AIR_HIT_GROUND_SLAMMED,
		/*  97 */ ACTION_KNOCKED_DOWN = 97,
		/*  98 */ ACTION_KNOCKED_DOWN_STATIC, //At this point, the character is not bouncing or moving anymore

		/* 100 */ ACTION_GRABBED = 100,
		/* 143 */ ACTION_GROUND_CRUSHED = 143,
		/* 145 */ ACTION_AIR_CRUSHED = 145,
		/* 150 */ ACTION_RIGHTBLOCK_HIGH_SMALL_BLOCKSTUN = 150,
		/* 151 */ ACTION_RIGHTBLOCK_HIGH_MEDIUM_BLOCKSTUN,
		/* 152 */ ACTION_RIGHTBLOCK_HIGH_BIG_BLOCKSTUN,
		/* 153 */ ACTION_RIGHTBLOCK_HIGH_HUGE_BLOCKSTUN,
		/* 154 */ ACTION_RIGHTBLOCK_LOW_SMALL_BLOCKSTUN,
		/* 155 */ ACTION_RIGHTBLOCK_LOW_MEDIUM_BLOCKSTUN,
		/* 156 */ ACTION_RIGHTBLOCK_LOW_BIG_BLOCKSTUN,
		/* 157 */ ACTION_RIGHTBLOCK_LOW_HUGE_BLOCKSTUN,
		/* 158 */ ACTION_AIR_GUARD,
		/* 159 */ ACTION_WRONGBLOCK_HIGH_SMALL_BLOCKSTUN,
		/* 160 */ ACTION_WRONGBLOCK_HIGH_MEDIUM_BLOCKSTUN,
		/* 161 */ ACTION_WRONGBLOCK_HIGH_BIG_BLOCKSTUN,
		/* 162 */ ACTION_WRONGBLOCK_HIGH_HUGE_BLOCKSTUN,
		/* 163 */ ACTION_WRONGBLOCK_LOW_SMALL_BLOCKSTUN,
		/* 164 */ ACTION_WRONGBLOCK_LOW_MEDIUM_BLOCKSTUN,
		/* 165 */ ACTION_WRONGBLOCK_LOW_BIG_BLOCKSTUN,
		/* 166 */ ACTION_WRONGBLOCK_LOW_HUGE_BLOCKSTUN,
		/* 180 */ ACTION_FORWARD_AIRTECH = 180,
		/* 181 */ ACTION_BACKWARD_AIRTECH,
		/* 197 */ ACTION_FORWARD_TECH = 197,
		/* 198 */ ACTION_BACKWARD_TECH,
		/* 199 */ ACTION_NEUTRAL_TECH,

		/* 200 */ ACTION_FORWARD_DASH,
		/* 201 */ ACTION_BACKDASH,
		/* 202 */ ACTION_FORWARD_AIRDASH,
		/* 203 */ ACTION_BACKWARD_AIRDASH,
		/* 204 */ ACTION_GROUNDDASH_RECOVERY,
		/* 206 */ ACTION_LILYPAD_FORWARD_DASH = 206,
		/* 207 */ ACTION_LILYPAD_BACKDASH,
		/* 208 */ ACTION_NEUTRAL_HIGH_JUMP,
		/* 209 */ ACTION_FORWARD_HIGH_JUMP,
		/* 210 */ ACTION_BACKWARD_HIGH_JUMP,
		/* 211 */ ACTION_NEUTRAL_HIGH_JUMP_FROM_GROUND_DASH,
		/* 212 */ ACTION_FORWARD_HIGH_JUMP_FROM_GROUND_DASH,
		/* 214 */ ACTION_FLY = 214,
		/* 215 */ ACTION_HARDLAND = 215,
		/* 218 */ ACTION_SUWAKO_j2D = 218,
		/* 219 */ ACTION_SUWAKO_j1D_j3D,
		/* 220 */ ACTION_BE2,
		/* 222 */ ACTION_BE1 = 222,
		/* 223 */ ACTION_BE6,
		/* 224 */ ACTION_BE4,
		/* 225 */ ACTION_jBE4,
		/* 226 */ ACTION_jBE6,

		/* 300 */ ACTION_5A = 300,
		/* 301 */ ACTION_f5A,
		/* 302 */ ACTION_6A,
		/* 303 */ ACTION_2A,
		/* 304 */ ACTION_3A,
		/* 305 */ ACTION_66A,
		/* 306 */ ACTION_j5A,
		/* 307 */ ACTION_j6A,
		/* 308 */ ACTION_j2A,
		/* 309 */ ACTION_j8A,
		/* 311 */ ACTION_f2A = 311,
		/* 320 */ ACTION_5AA = 320,
		/* 321 */ ACTION_5AAA,
		/* 322 */ ACTION_5AAAA,
		/* 323 */ ACTION_5AAAAA,
		/* 324 */ ACTION_5AAA3A,
		/* 325 */ ACTION_j5AA,
		/* 330 */ ACTION_4A = 330,
		/* 331 */ ACTION_SUWAKO_3A,
		/* 332 */ ACTION_SUWAKO_LILYPAD_6A,

		/* 400 */ ACTION_5B = 400,
		/* 401 */ ACTION_6B,
		/* 402 */ ACTION_2B,
		/* 403 */ ACTION_3B,
		/* 404 */ ACTION_j5B,
		/* 405 */ ACTION_j6B,
		/* 406 */ ACTION_j2B,
		/* 407 */ ACTION_4B,
		/* 408 */ ACTION_66B,
		/* 409 */ ACTION_j4B,
		/* 410 */ ACTION_5C,
		/* 411 */ ACTION_6C,
		/* 412 */ ACTION_2C,
		/* 413 */ ACTION_4C,
		/* 414 */ ACTION_j5C,
		/* 415 */ ACTION_j6C,
		/* 416 */ ACTION_j2C,
		/* 417 */ ACTION_j1C,
		/* 418 */ ACTION_66C,
		/* 419 */ ACTION_ALICE_4C,
		/* 420 */ ACTION_ORRERIES_B,
		/* 422 */ ACTION_AIR_ORRERIES_B = 422,
		/* 430 */ ACTION_ORRERIES_C = 430,
		/* 432 */ ACTION_AIR_ORRERIES_C = 432,

		/* 500 */ ACTION_DEFAULT_SKILL1_B = 500,
		/* 501 */ ACTION_DEFAULT_SKILL1_C,
		/* 502 */ ACTION_DEFAULT_SKILL1_AIR_B,
		/* 503 */ ACTION_DEFAULT_SKILL1_AIR_C,
		/* 505 */ ACTION_ALT1_SKILL1_B = 505,
		/* 506 */ ACTION_ALT1_SKILL1_C,
		/* 507 */ ACTION_ALT1_SKILL1_AIR_B,
		/* 508 */ ACTION_ALT1_SKILL1_AIR_C,
		/* 510 */ ACTION_ALT2_SKILL1_B = 510,
		/* 511 */ ACTION_ALT2_SKILL1_C,
		/* 512 */ ACTION_ALT2_SKILL1_AIR_B,
		/* 513 */ ACTION_ALT2_SKILL1_AIR_C,
		/* 520 */ ACTION_DEFAULT_SKILL2_B = 520,
		/* 521 */ ACTION_DEFAULT_SKILL2_C,
		/* 522 */ ACTION_DEFAULT_SKILL2_AIR_B,
		/* 523 */ ACTION_DEFAULT_SKILL2_AIR_C,
		/* 525 */ ACTION_ALT1_SKILL2_B = 525,
		/* 526 */ ACTION_ALT1_SKILL2_C,
		/* 527 */ ACTION_ALT1_SKILL2_AIR_B,
		/* 528 */ ACTION_ALT1_SKILL2_AIR_C,
		/* 530 */ ACTION_ALT2_SKILL2_B = 530,
		/* 531 */ ACTION_ALT2_SKILL2_C,
		/* 532 */ ACTION_ALT2_SKILL2_AIR_B,
		/* 533 */ ACTION_ALT2_SKILL2_AIR_C,
		/* 540 */ ACTION_DEFAULT_SKILL3_B = 540,
		/* 541 */ ACTION_DEFAULT_SKILL3_C,
		/* 542 */ ACTION_DEFAULT_SKILL3_AIR_B,
		/* 543 */ ACTION_DEFAULT_SKILL3_AIR_C,
		/* 545 */ ACTION_ALT1_SKILL3_B = 545,
		/* 546 */ ACTION_ALT1_SKILL3_C,
		/* 547 */ ACTION_ALT1_SKILL3_AIR_B,
		/* 548 */ ACTION_ALT1_SKILL3_AIR_C,
		/* 550 */ ACTION_ALT2_SKILL3_B = 550,
		/* 551 */ ACTION_ALT2_SKILL3_C,
		/* 552 */ ACTION_ALT2_SKILL3_AIR_B,
		/* 553 */ ACTION_ALT2_SKILL3_AIR_C,
		/* 560 */ ACTION_DEFAULT_SKILL4_B = 560,
		/* 561 */ ACTION_DEFAULT_SKILL4_C,
		/* 562 */ ACTION_DEFAULT_SKILL4_AIR_B,
		/* 563 */ ACTION_DEFAULT_SKILL4_AIR_C,
		/* 565 */ ACTION_ALT1_SKILL4_B = 565,
		/* 566 */ ACTION_ALT1_SKILL4_C,
		/* 567 */ ACTION_ALT1_SKILL4_AIR_B,
		/* 568 */ ACTION_ALT1_SKILL4_AIR_C,
		/* 570 */ ACTION_ALT2_SKILL4_B = 570,
		/* 571 */ ACTION_ALT2_SKILL4_C,
		/* 572 */ ACTION_ALT2_SKILL4_AIR_B,
		/* 573 */ ACTION_ALT2_SKILL4_AIR_C,
		/* 580 */ ACTION_DEFAULT_SKILL5_B = 580,
		/* 581 */ ACTION_DEFAULT_SKILL5_C,
		/* 582 */ ACTION_DEFAULT_SKILL5_AIR_B,
		/* 583 */ ACTION_DEFAULT_SKILL5_AIR_C,
		/* 585 */ ACTION_ALT1_SKILL5_B = 585,
		/* 586 */ ACTION_ALT1_SKILL5_C,
		/* 587 */ ACTION_ALT1_SKILL5_AIR_B,
		/* 588 */ ACTION_ALT1_SKILL5_AIR_C,
		/* 590 */ ACTION_ALT2_SKILL5_B = 590,
		/* 591 */ ACTION_ALT2_SKILL5_C,
		/* 592 */ ACTION_ALT2_SKILL5_AIR_B,
		/* 593 */ ACTION_ALT2_SKILL5_AIR_C,

		/* 600 */ ACTION_USING_SC_ID_200 = 600,
		/* 601 */ ACTION_USING_SC_ID_201,
		/* 602 */ ACTION_USING_SC_ID_202,
		/* 603 */ ACTION_USING_SC_ID_203,
		/* 604 */ ACTION_USING_SC_ID_204,
		/* 605 */ ACTION_USING_SC_ID_205,
		/* 606 */ ACTION_USING_SC_ID_206,
		/* 607 */ ACTION_USING_SC_ID_207,
		/* 608 */ ACTION_USING_SC_ID_208,
		/* 609 */ ACTION_USING_SC_ID_209,
		/* 610 */ ACTION_USING_SC_ID_210,
		/* 611 */ ACTION_USING_SC_ID_211,
		/* 612 */ ACTION_USING_SC_ID_212,
		/* 613 */ ACTION_USING_SC_ID_213,
		/* 614 */ ACTION_USING_SC_ID_214,
		/* 615 */ ACTION_USING_SC_ID_215,
		/* 616 */ ACTION_USING_SC_ID_216,
		/* 617 */ ACTION_USING_SC_ID_217,
		/* 618 */ ACTION_USING_SC_ID_218,
		/* 619 */ ACTION_USING_SC_ID_219,

		/* 650 */ ACTION_SC_ID_200_ALT_EFFECT = 650,
		/* 651 */ ACTION_SC_ID_201_ALT_EFFECT,
		/* 652 */ ACTION_SC_ID_202_ALT_EFFECT,
		/* 653 */ ACTION_SC_ID_203_ALT_EFFECT,
		/* 654 */ ACTION_SC_ID_204_ALT_EFFECT,
		/* 655 */ ACTION_SC_ID_205_ALT_EFFECT,
		/* 656 */ ACTION_SC_ID_206_ALT_EFFECT,
		/* 657 */ ACTION_SC_ID_207_ALT_EFFECT,
		/* 658 */ ACTION_SC_ID_208_ALT_EFFECT,
		/* 659 */ ACTION_SC_ID_209_ALT_EFFECT,
		/* 660 */ ACTION_SC_ID_210_ALT_EFFECT,
		/* 661 */ ACTION_SC_ID_211_ALT_EFFECT,
		/* 662 */ ACTION_SC_ID_212_ALT_EFFECT,
		/* 663 */ ACTION_SC_ID_213_ALT_EFFECT,
		/* 664 */ ACTION_SC_ID_214_ALT_EFFECT,
		/* 665 */ ACTION_SC_ID_215_ALT_EFFECT,
		/* 666 */ ACTION_SC_ID_216_ALT_EFFECT,
		/* 667 */ ACTION_SC_ID_217_ALT_EFFECT,
		/* 668 */ ACTION_SC_ID_218_ALT_EFFECT,
		/* 669 */ ACTION_SC_ID_219_ALT_EFFECT,
		/* 669 */ ACTION_FANTASY_HEAVEN_ACTIVATE = ACTION_SC_ID_219_ALT_EFFECT,

		/* 690 */ ACTION_SKILL_CARD = 690,
		/* 691 */ ACTION_SYSTEM_CARD,
		/* 692 */ ACTION_IBUKI_GOURD,
		/* 693 */ ACTION_RECOVERY_CHARM,
		/* 694 */ ACTION_MAGIC_POTION,
		/* 695 */ ACTION_TALISMAN,
		/* 695 */ ACTION_BOMB = ACTION_TALISMAN,
		/* 696 */ ACTION_HANGEKI,
		/* 696 */ ACTION_DIVINE_RAIMENT_OF_THE_DRAGON_FISH = ACTION_HANGEKI,
		/* 697 */ ACTION_LEFT_HANDED_FOLDING_FAN,
		/* 698 */ ACTION_SPELL_BREAKING_DRUG,
	};
}

#endif //SOKULIB_ACTION_HPP
