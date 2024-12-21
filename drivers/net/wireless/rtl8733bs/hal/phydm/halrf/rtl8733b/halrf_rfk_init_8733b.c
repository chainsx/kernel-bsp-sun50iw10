/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/

#include "mp_precomp.h"
#if (DM_ODM_SUPPORT_TYPE == 0x08)
#if RT_PLATFORM == PLATFORM_MACOSX
#include "phydm_precomp.h"
#else
#include "../phydm_precomp.h"
#endif
#else
#include "../../phydm_precomp.h"
#endif

#if (RTL8733B_SUPPORT == 1)

u32 array_mp_8733b_cal_init[] = {
	0x1cd0, 0x7f000000,
	0x1b80, 0x00000004, /*enable access page 1b register*/
	0x1b00, 0x00000008,
	0x1b08, 0x00000000,
	/*NBIQK PHY SETTING*/
	0x1b04, 0xF0862966,
	0x1b0c, 0x78000000,
	0x1b10, 0x88013100,
	0x1b14, 0x00010100,
	0x1b18, 0x10010100,
	0x1b1c, 0xA2103C00,
	0x1b20, 0x030403E0,
	0x1b24, 0x00072160,
	0x1b28, 0x00180e00,
	0x1b30, 0x0000ff09,
	0x1b34, 0x56440834,
	0x1b38, 0x20000003,
	0x1b3c, 0x20000000,
	0x1b38, 0x20000001,
	0x1b3c, 0x20000000,
	0x1b34, 0x5644081c,
	0x1b38, 0x20000003,
	0x1b3c, 0x20000000,
	0x1b38, 0x20000001,
	0x1b3c, 0x20000000,
	0x1bc0, 0x0010001F,
	0x1be4, 0xf0000003,
	0x1bd0, 0x80006143,
	0x1bd0, 0x00006143,
	0x1bc0, 0x0010201f,
	0x1bd0, 0x80008585,
	0x1bd0, 0x00008585,
	0x1bb8, 0x00000000,
	/*DPK PHY setting 0623*/
	0x1b8c, 0xfcff4c00, /*gainloss + lut table sel off*/
	0x1b90, 0x0105f018,
	0x1b94, 0xf76d9f84,
	0x1bc8, 0x000c5599,
	0x1bcc, 0x11160200,
	0x1bd8, 0x00000000, /*RXSRAM control*/
	0x1bf8, 0x00000080, /*auto cal mean_phase_val*/
	0x1be0, 0x20000000, /*bypass RX DC_i/q*/
	/*set pwsf_k table*/
	0x1bc4, 0x00190019,
	0x1bb8, 0x00000001,
	0x1bb8, 0x00000000,
	0x1bbc, 0x00097e5f, /*TXAGC_boundary: ant1: 1F; 12;ant0: 1F ; 12;*/
	/*tx_amp*/
	0x1b98, 0x41382e21,
	0x1b9c, 0x5b554f48,
	0x1ba0, 0x6f6b6661,
	0x1ba4, 0x817d7874,
	0x1ba8, 0x908c8884,
	0x1bac, 0x9d9a9793,
	0x1bb0, 0xaaa7a4a1,
	0x1bb4, 0xb6b3b0ad,
	/*tx_inverse*/
	0x1b40, 0x02ce03e9,
	0x1b44, 0x01fd0249,
	0x1b48, 0x01a101c9,
	0x1b4c, 0x016a0181,
	0x1b50, 0x01430155,
	0x1b54, 0x01270135,
	0x1b58, 0x0112011c,
	0x1b5c, 0x01000108,
	0x1b60, 0x00f100f8,
	0x1b64, 0x00e500eb,
	0x1b68, 0x00db00e0,
	0x1b6c, 0x00d100d5,
	0x1b70, 0x00c900cd,
	0x1b74, 0x00c200c5,
	0x1b78, 0x00bb00be,
	0x1b7c, 0x00b500b8,
	/*PWSF_SRAM_write 0.125dB*/
	0x1bdc, 0x00000000,
	0x1bdc, 0x40070181,
	0x1bdc, 0x40070783,
	0x1bdc, 0x40080785,
	0x1bdc, 0x40080887,
	0x1bdc, 0x40090889,
	0x1bdc, 0x4009098B,
	0x1bdc, 0x400A098D,
	0x1bdc, 0x400A0A8F,
	0x1bdc, 0x400B0A91,
	0x1bdc, 0x400B0B93,
	0x1bdc, 0x400C0C95,
	0x1bdc, 0x400D0C97,
	0x1bdc, 0x400E0D99,
	0x1bdc, 0x400E0E9B,
	0x1bdc, 0x400F0F9D,
	0x1bdc, 0x4010109F,
	0x1bdc, 0x401111A1,
	0x1bdc, 0x401212A3,
	0x1bdc, 0x401313A5,
	0x1bdc, 0x401414A7,
	0x1bdc, 0x401515A9,
	0x1bdc, 0x401716AB,
	0x1bdc, 0x401817AD,
	0x1bdc, 0x401919AF,
	0x1bdc, 0x401B1AB1,
	0x1bdc, 0x401D1CB3,
	0x1bdc, 0x401E1DB5,
	0x1bdc, 0x40201FB7,
	0x1bdc, 0x402221B9,
	0x1bdc, 0x402423BB,
	0x1bdc, 0x402625BD,
	0x1bdc, 0x402827BF,
	0x1bdc, 0x402B2AC1,
	0x1bdc, 0x402D2CC3,
	0x1bdc, 0x40302FC5,
	0x1bdc, 0x403331C7,
	0x1bdc, 0x403634C9,
	0x1bdc, 0x403937CB,
	0x1bdc, 0x403C3BCD,
	0x1bdc, 0x40403ECF,
	0x1bdc, 0x404442D1,
	0x1bdc, 0x404846D3,
	0x1bdc, 0x404C4AD5,
	0x1bdc, 0x40514ED7,
	0x1bdc, 0x405553D9,
	0x1bdc, 0x405A58DB,
	0x1bdc, 0x40605DDD,
	0x1bdc, 0x406563DF,
	0x1bdc, 0x406B68E1,
	0x1bdc, 0x40726FE3,
	0x1bdc, 0x407975E5,
	0x1bdc, 0x40807CE7,
	0x1bdc, 0x408783E9,
	0x1bdc, 0x408F8BEB,
	0x1bdc, 0x409893ED,
	0x1bdc, 0x40A19CEF,
	0x1bdc, 0x40AAA5F1,
	0x1bdc, 0x40B4AFF3,
	0x1bdc, 0x40BFBAF5,
	0x1bdc, 0x40CAC5F7,
	0x1bdc, 0x40D6D0F9,
	0x1bdc, 0x40E3DDFB,
	0x1bdc, 0x40F1EAFD,
	0x1bdc, 0x40FFF8FF,
	0x1bdc, 0x00000000,
	/*clear even*/
	0x1bdc, 0xd0000001,
	0x1bdc, 0xd0000003,
	0x1bdc, 0xd0000005,
	0x1bdc, 0xd0000007,
	0x1bdc, 0xd0000009,
	0x1bdc, 0xd000000b,
	0x1bdc, 0xd000000d,
	0x1bdc, 0xd000000f,
	0x1bdc, 0xd0000011,
	0x1bdc, 0xd0000013,
	0x1bdc, 0xd0000015,
	0x1bdc, 0xd0000017,
	0x1bdc, 0xd0000019,
	0x1bdc, 0xd000001b,
	0x1bdc, 0xd000001d,
	0x1bdc, 0xd000001f,
	0x1bdc, 0xd0000021,
	0x1bdc, 0xd0000023,
	0x1bdc, 0xd0000025,
	0x1bdc, 0xd0000027,
	0x1bdc, 0xd0000029,
	0x1bdc, 0xd000002b,
	0x1bdc, 0xd000002d,
	0x1bdc, 0xd000002f,
	0x1bdc, 0xd0000031,
	0x1bdc, 0xd0000033,
	0x1bdc, 0xd0000035,
	0x1bdc, 0xd0000037,
	0x1bdc, 0xd0000039,
	0x1bdc, 0xd000003b,
	0x1bdc, 0xd000003d,
	0x1bdc, 0xd000003f,
	/*clear odd*/
	0x1bdc, 0x90000081,
	0x1bdc, 0x90000083,
	0x1bdc, 0x90000085,
	0x1bdc, 0x90000087,
	0x1bdc, 0x90000089,
	0x1bdc, 0x9000008b,
	0x1bdc, 0x9000008d,
	0x1bdc, 0x9000008f,
	0x1bdc, 0x90000091,
	0x1bdc, 0x90000093,
	0x1bdc, 0x90000095,
	0x1bdc, 0x90000097,
	0x1bdc, 0x90000099,
	0x1bdc, 0x9000009b,
	0x1bdc, 0x9000009d,
	0x1bdc, 0x9000009f,
	0x1bdc, 0x900000a1,
	0x1bdc, 0x900000a3,
	0x1bdc, 0x900000a5,
	0x1bdc, 0x900000a7,
	0x1bdc, 0x900000a9,
	0x1bdc, 0x900000ab,
	0x1bdc, 0x900000ad,
	0x1bdc, 0x900000af,
	0x1bdc, 0x900000b1,
	0x1bdc, 0x900000b3,
	0x1bdc, 0x900000b5,
	0x1bdc, 0x900000b7,
	0x1bdc, 0x900000b9,
	0x1bdc, 0x900000bb,
	0x1bdc, 0x900000bd,
	0x1bdc, 0x900000bf,
	0x1bdc, 0x00000000,
	/*NCTL setting 0701*/
	0x1b00, 0x00000008,
	0x1b80, 0x00000007,
	0x1b80, 0x090a0005,
	0x1b80, 0x090a0007,
	0x1b80, 0x0ffe0015,
	0x1b80, 0x0ffe0017,
	0x1b80, 0x00220025,
	0x1b80, 0x00220027,
	0x1b80, 0x00040035,
	0x1b80, 0x00040037,
	0x1b80, 0x05c00045,
	0x1b80, 0x05c00047,
	0x1b80, 0x00020055,
	0x1b80, 0x00020057,
	0x1b80, 0x00040065,
	0x1b80, 0x00040067,
	0x1b80, 0x73000075,
	0x1b80, 0x73000077,
	0x1b80, 0x00080085,
	0x1b80, 0x00080087,
	0x1b80, 0x80000095,
	0x1b80, 0x80000097,
	0x1b80, 0x090800a5,
	0x1b80, 0x090800a7,
	0x1b80, 0x0f0200b5,
	0x1b80, 0x0f0200b7,
	0x1b80, 0x002200c5,
	0x1b80, 0x002200c7,
	0x1b80, 0x000400d5,
	0x1b80, 0x000400d7,
	0x1b80, 0x05c000e5,
	0x1b80, 0x05c000e7,
	0x1b80, 0x000200f5,
	0x1b80, 0x000200f7,
	0x1b80, 0x00040105,
	0x1b80, 0x00040107,
	0x1b80, 0x73010115,
	0x1b80, 0x73010117,
	0x1b80, 0x00040125,
	0x1b80, 0x00040127,
	0x1b80, 0x4a000135,
	0x1b80, 0x4a000137,
	0x1b80, 0x4b040145,
	0x1b80, 0x4b040147,
	0x1b80, 0x86040155,
	0x1b80, 0x86040157,
	0x1b80, 0x40090165,
	0x1b80, 0x40090167,
	0x1b80, 0x78010175,
	0x1b80, 0x78010177,
	0x1b80, 0xe0240185,
	0x1b80, 0xe0240187,
	0x1b80, 0x4b050195,
	0x1b80, 0x4b050197,
	0x1b80, 0x870401a5,
	0x1b80, 0x870401a7,
	0x1b80, 0x400b01b5,
	0x1b80, 0x400b01b7,
	0x1b80, 0x780301c5,
	0x1b80, 0x780301c7,
	0x1b80, 0xe02401d5,
	0x1b80, 0xe02401d7,
	0x1b80, 0x4b0001e5,
	0x1b80, 0x4b0001e7,
	0x1b80, 0x000701f5,
	0x1b80, 0x000701f7,
	0x1b80, 0x4c000205,
	0x1b80, 0x4c000207,
	0x1b80, 0x00040215,
	0x1b80, 0x00040217,
	0x1b80, 0x50550225,
	0x1b80, 0x50550227,
	0x1b80, 0x30000235,
	0x1b80, 0x30000237,
	0x1b80, 0xa5090245,
	0x1b80, 0xa5090247,
	0x1b80, 0xe14b0255,
	0x1b80, 0xe14b0257,
	0x1b80, 0xf00c0265,
	0x1b80, 0xf00c0267,
	0x1b80, 0xf10c0275,
	0x1b80, 0xf10c0277,
	0x1b80, 0xf20c0285,
	0x1b80, 0xf20c0287,
	0x1b80, 0xf30c0295,
	0x1b80, 0xf30c0297,
	0x1b80, 0xf40c02a5,
	0x1b80, 0xf40c02a7,
	0x1b80, 0xf50c02b5,
	0x1b80, 0xf50c02b7,
	0x1b80, 0xf60c02c5,
	0x1b80, 0xf60c02c7,
	0x1b80, 0xf10c02d5,
	0x1b80, 0xf10c02d7,
	0x1b80, 0xf20c02e5,
	0x1b80, 0xf20c02e7,
	0x1b80, 0xf30c02f5,
	0x1b80, 0xf30c02f7,
	0x1b80, 0xf40c0305,
	0x1b80, 0xf40c0307,
	0x1b80, 0x00010315,
	0x1b80, 0x00010317,
	0x1b80, 0x303d0325,
	0x1b80, 0x303d0327,
	0x1b80, 0x303e0335,
	0x1b80, 0x303e0337,
	0x1b80, 0x303f0345,
	0x1b80, 0x303f0347,
	0x1b80, 0x30410355,
	0x1b80, 0x30410357,
	0x1b80, 0x30460365,
	0x1b80, 0x30460367,
	0x1b80, 0x30480375,
	0x1b80, 0x30480377,
	0x1b80, 0x30710385,
	0x1b80, 0x30710387,
	0x1b80, 0x30740395,
	0x1b80, 0x30740397,
	0x1b80, 0x308303a5,
	0x1b80, 0x308303a7,
	0x1b80, 0x308d03b5,
	0x1b80, 0x308d03b7,
	0x1b80, 0x30a603c5,
	0x1b80, 0x30a603c7,
	0x1b80, 0x000103d5,
	0x1b80, 0x000103d7,
	0x1b80, 0x000103e5,
	0x1b80, 0x000103e7,
	0x1b80, 0xe0cb03f5,
	0x1b80, 0xe0cb03f7,
	0x1b80, 0x00010405,
	0x1b80, 0x00010407,
	0x1b80, 0x5b300415,
	0x1b80, 0x5b300417,
	0x1b80, 0x55000425,
	0x1b80, 0x55000427,
	0x1b80, 0x4d000435,
	0x1b80, 0x4d000437,
	0x1b80, 0xe0bf0445,
	0x1b80, 0xe0bf0447,
	0x1b80, 0x00010455,
	0x1b80, 0x00010457,
	0x1b80, 0xe0ff0465,
	0x1b80, 0xe0ff0467,
	0x1b80, 0x00010475,
	0x1b80, 0x00010477,
	0x1b80, 0x00070485,
	0x1b80, 0x00070487,
	0x1b80, 0x745c0495,
	0x1b80, 0x745c0497,
	0x1b80, 0x722004a5,
	0x1b80, 0x722004a7,
	0x1b80, 0x720004b5,
	0x1b80, 0x720004b7,
	0x1b80, 0x000404c5,
	0x1b80, 0x000404c7,
	0x1b80, 0x550104d5,
	0x1b80, 0x550104d7,
	0x1b80, 0x5b4004e5,
	0x1b80, 0x5b4004e7,
	0x1b80, 0x5c3104f5,
	0x1b80, 0x5c3104f7,
	0x1b80, 0x5fa20505,
	0x1b80, 0x5fa20507,
	0x1b80, 0x66050515,
	0x1b80, 0x66050517,
	0x1b80, 0x08010525,
	0x1b80, 0x08010527,
	0x1b80, 0x09000535,
	0x1b80, 0x09000537,
	0x1b80, 0x0a010545,
	0x1b80, 0x0a010547,
	0x1b80, 0x0b400555,
	0x1b80, 0x0b400557,
	0x1b80, 0x0d000565,
	0x1b80, 0x0d000567,
	0x1b80, 0x0c010575,
	0x1b80, 0x0c010577,
	0x1b80, 0x002a0585,
	0x1b80, 0x002a0587,
	0x1b80, 0x00040595,
	0x1b80, 0x00040597,
	0x1b80, 0x7f2005a5,
	0x1b80, 0x7f2005a7,
	0x1b80, 0x000705b5,
	0x1b80, 0x000705b7,
	0x1b80, 0x057205c5,
	0x1b80, 0x057205c7,
	0x1b80, 0x053305d5,
	0x1b80, 0x053305d7,
	0x1b80, 0x960405e5,
	0x1b80, 0x960405e7,
	0x1b80, 0xe12005f5,
	0x1b80, 0xe12005f7,
	0x1b80, 0x00040605,
	0x1b80, 0x00040607,
	0x1b80, 0xe0bf0615,
	0x1b80, 0xe0bf0617,
	0x1b80, 0x7f210625,
	0x1b80, 0x7f210627,
	0x1b80, 0x00070635,
	0x1b80, 0x00070637,
	0x1b80, 0x06320645,
	0x1b80, 0x06320647,
	0x1b80, 0x07330655,
	0x1b80, 0x07330657,
	0x1b80, 0x96060665,
	0x1b80, 0x96060667,
	0x1b80, 0xe1200675,
	0x1b80, 0xe1200677,
	0x1b80, 0x00040685,
	0x1b80, 0x00040687,
	0x1b80, 0xe0bf0695,
	0x1b80, 0xe0bf0697,
	0x1b80, 0x000706a5,
	0x1b80, 0x000706a7,
	0x1b80, 0xe11806b5,
	0x1b80, 0xe11806b7,
	0x1b80, 0x000206c5,
	0x1b80, 0x000206c7,
	0x1b80, 0xe11c06d5,
	0x1b80, 0xe11c06d7,
	0x1b80, 0x000406e5,
	0x1b80, 0x000406e7,
	0x1b80, 0x5f8206f5,
	0x1b80, 0x5f8206f7,
	0x1b80, 0x00010705,
	0x1b80, 0x00010707,
	0x1b80, 0x00070715,
	0x1b80, 0x00070717,
	0x1b80, 0x745e0725,
	0x1b80, 0x745e0727,
	0x1b80, 0x304a0735,
	0x1b80, 0x304a0737,
	0x1b80, 0x00040745,
	0x1b80, 0x00040747,
	0x1b80, 0x63000755,
	0x1b80, 0x63000757,
	0x1b80, 0x00070765,
	0x1b80, 0x00070767,
	0x1b80, 0x4e160775,
	0x1b80, 0x4e160777,
	0x1b80, 0x4f110785,
	0x1b80, 0x4f110787,
	0x1b80, 0x00060795,
	0x1b80, 0x00060797,
	0x1b80, 0x57f707a5,
	0x1b80, 0x57f707a7,
	0x1b80, 0x4b0007b5,
	0x1b80, 0x4b0007b7,
	0x1b80, 0x4b0107c5,
	0x1b80, 0x4b0107c7,
	0x1b80, 0x4b0007d5,
	0x1b80, 0x4b0007d7,
	0x1b80, 0x000407e5,
	0x1b80, 0x000407e7,
	0x1b80, 0x930007f5,
	0x1b80, 0x930007f7,
	0x1b80, 0xb0300805,
	0x1b80, 0xb0300807,
	0x1b80, 0x30830815,
	0x1b80, 0x30830817,
	0x1b80, 0x00010825,
	0x1b80, 0x00010827,
	0x1b80, 0x00070835,
	0x1b80, 0x00070837,
	0x1b80, 0x4e160845,
	0x1b80, 0x4e160847,
	0x1b80, 0x4f110855,
	0x1b80, 0x4f110857,
	0x1b80, 0x00060865,
	0x1b80, 0x00060867,
	0x1b80, 0x44000875,
	0x1b80, 0x44000877,
	0x1b80, 0x44800885,
	0x1b80, 0x44800887,
	0x1b80, 0x44000895,
	0x1b80, 0x44000897,
	0x1b80, 0x000408a5,
	0x1b80, 0x000408a7,
	0x1b80, 0x8d0008b5,
	0x1b80, 0x8d0008b7,
	0x1b80, 0x000108c5,
	0x1b80, 0x000108c7,
	0x1b80, 0x000608d5,
	0x1b80, 0x000608d7,
	0x1b80, 0x50b808e5,
	0x1b80, 0x50b808e7,
	0x1b80, 0x51e008f5,
	0x1b80, 0x51e008f7,
	0x1b80, 0x520d0905,
	0x1b80, 0x520d0907,
	0x1b80, 0x53020915,
	0x1b80, 0x53020917,
	0x1b80, 0x57f70925,
	0x1b80, 0x57f70927,
	0x1b80, 0x00070935,
	0x1b80, 0x00070937,
	0x1b80, 0x7b000945,
	0x1b80, 0x7b000947,
	0x1b80, 0x4a000955,
	0x1b80, 0x4a000957,
	0x1b80, 0x4c3f0965,
	0x1b80, 0x4c3f0967,
	0x1b80, 0x4e840975,
	0x1b80, 0x4e840977,
	0x1b80, 0x4f030985,
	0x1b80, 0x4f030987,
	0x1b80, 0x00040995,
	0x1b80, 0x00040997,
	0x1b80, 0x630109a5,
	0x1b80, 0x630109a7,
	0x1b80, 0x740009b5,
	0x1b80, 0x740009b7,
	0x1b80, 0x740209c5,
	0x1b80, 0x740209c7,
	0x1b80, 0x740009d5,
	0x1b80, 0x740009d7,
	0x1b80, 0x8b0009e5,
	0x1b80, 0x8b0009e7,
	0x1b80, 0xab0009f5,
	0x1b80, 0xab0009f7,
	0x1b80, 0xaa100a05,
	0x1b80, 0xaa100a07,
	0x1b80, 0x00070a15,
	0x1b80, 0x00070a17,
	0x1b80, 0x4c000a25,
	0x1b80, 0x4c000a27,
	0x1b80, 0x00040a35,
	0x1b80, 0x00040a37,
	0x1b80, 0x63000a45,
	0x1b80, 0x63000a47,
	0x1b80, 0x00010a55,
	0x1b80, 0x00010a57,
	0x1b80, 0x00060a65,
	0x1b80, 0x00060a67,
	0x1b80, 0x57770a75,
	0x1b80, 0x57770a77,
	0x1b80, 0x50180a85,
	0x1b80, 0x50180a87,
	0x1b80, 0x00070a95,
	0x1b80, 0x00070a97,
	0x1b80, 0x4b000aa5,
	0x1b80, 0x4b000aa7,
	0x1b80, 0x4e020ab5,
	0x1b80, 0x4e020ab7,
	0x1b80, 0x4f110ac5,
	0x1b80, 0x4f110ac7,
	0x1b80, 0x00040ad5,
	0x1b80, 0x00040ad7,
	0x1b80, 0x63050ae5,
	0x1b80, 0x63050ae7,
	0x1b80, 0x00010af5,
	0x1b80, 0x00010af7,
	0x1b80, 0x301f0b05,
	0x1b80, 0x301f0b07,
	0x1b80, 0x00010b15,
	0x1b80, 0x00010b17,
	0x1b80, 0x7b240b25,
	0x1b80, 0x7b240b27,
	0x1b80, 0x7a400b35,
	0x1b80, 0x7a400b37,
	0x1b80, 0x79000b45,
	0x1b80, 0x79000b47,
	0x1b80, 0x55030b55,
	0x1b80, 0x55030b57,
	0x1b80, 0x4d0c0b65,
	0x1b80, 0x4d0c0b67,
	0x1b80, 0x30bf0b75,
	0x1b80, 0x30bf0b77,
	0x1b80, 0x7b1c0b85,
	0x1b80, 0x7b1c0b87,
	0x1b80, 0x7a400b95,
	0x1b80, 0x7a400b97,
	0x1b80, 0x55130ba5,
	0x1b80, 0x55130ba7,
	0x1b80, 0x30bf0bb5,
	0x1b80, 0x30bf0bb7,
	0x1b80, 0x7b200bc5,
	0x1b80, 0x7b200bc7,
	0x1b80, 0x7a000bd5,
	0x1b80, 0x7a000bd7,
	0x1b80, 0x55230be5,
	0x1b80, 0x55230be7,
	0x1b80, 0x74010bf5,
	0x1b80, 0x74010bf7,
	0x1b80, 0x74000c05,
	0x1b80, 0x74000c07,
	0x1b80, 0x8e000c15,
	0x1b80, 0x8e000c17,
	0x1b80, 0x00010c25,
	0x1b80, 0x00010c27,
	0x1b80, 0x57020c35,
	0x1b80, 0x57020c37,
	0x1b80, 0x57000c45,
	0x1b80, 0x57000c47,
	0x1b80, 0x97000c55,
	0x1b80, 0x97000c57,
	0x1b80, 0x00010c65,
	0x1b80, 0x00010c67,
	0x1b80, 0x56110c75,
	0x1b80, 0x56110c77,
	0x1b80, 0x56010c85,
	0x1b80, 0x56010c87,
	0x1b80, 0x8c000c95,
	0x1b80, 0x8c000c97,
	0x1b80, 0x00010ca5,
	0x1b80, 0x00010ca7,
	0x1b80, 0x7f200cb5,
	0x1b80, 0x7f200cb7,
	0x1b80, 0x7e000cc5,
	0x1b80, 0x7e000cc7,
	0x1b80, 0x7d000cd5,
	0x1b80, 0x7d000cd7,
	0x1b80, 0x4d0c0ce5,
	0x1b80, 0x4d0c0ce7,
	0x1b80, 0x5b200cf5,
	0x1b80, 0x5b200cf7,
	0x1b80, 0x57000d05,
	0x1b80, 0x57000d07,
	0x1b80, 0x56000d15,
	0x1b80, 0x56000d17,
	0x1b80, 0x55000d25,
	0x1b80, 0x55000d27,
	0x1b80, 0x54000d35,
	0x1b80, 0x54000d37,
	0x1b80, 0x7b200d45,
	0x1b80, 0x7b200d47,
	0x1b80, 0x7a000d55,
	0x1b80, 0x7a000d57,
	0x1b80, 0x79000d65,
	0x1b80, 0x79000d67,
	0x1b80, 0x00070d75,
	0x1b80, 0x00070d77,
	0x1b80, 0x4f800d85,
	0x1b80, 0x4f800d87,
	0x1b80, 0x00040d95,
	0x1b80, 0x00040d97,
	0x1b80, 0xe0bf0da5,
	0x1b80, 0xe0bf0da7,
	0x1b80, 0xe12a0db5,
	0x1b80, 0xe12a0db7,
	0x1b80, 0xe12a0dc5,
	0x1b80, 0xe12a0dc7,
	0x1b80, 0xe12a0dd5,
	0x1b80, 0xe12a0dd7,
	0x1b80, 0xe12a0de5,
	0x1b80, 0xe12a0de7,
	0x1b80, 0x00070df5,
	0x1b80, 0x00070df7,
	0x1b80, 0x4f000e05,
	0x1b80, 0x4f000e07,
	0x1b80, 0x00040e15,
	0x1b80, 0x00040e17,
	0x1b80, 0x57000e25,
	0x1b80, 0x57000e27,
	0x1b80, 0x56010e35,
	0x1b80, 0x56010e37,
	0x1b80, 0x55010e45,
	0x1b80, 0x55010e47,
	0x1b80, 0x54000e55,
	0x1b80, 0x54000e57,
	0x1b80, 0x5a010e65,
	0x1b80, 0x5a010e67,
	0x1b80, 0x59010e75,
	0x1b80, 0x59010e77,
	0x1b80, 0x00010e85,
	0x1b80, 0x00010e87,
	0x1b80, 0x00010e95,
	0x1b80, 0x00010e97,
	0x1b80, 0x54a70ea5,
	0x1b80, 0x54a70ea7,
	0x1b80, 0x54c00eb5,
	0x1b80, 0x54c00eb7,
	0x1b80, 0x54a30ec5,
	0x1b80, 0x54a30ec7,
	0x1b80, 0x54c10ed5,
	0x1b80, 0x54c10ed7,
	0x1b80, 0x54a40ee5,
	0x1b80, 0x54a40ee7,
	0x1b80, 0x4c180ef5,
	0x1b80, 0x4c180ef7,
	0x1b80, 0xbf070f05,
	0x1b80, 0xbf070f07,
	0x1b80, 0x54c20f15,
	0x1b80, 0x54c20f17,
	0x1b80, 0x54a40f25,
	0x1b80, 0x54a40f27,
	0x1b80, 0xbf040f35,
	0x1b80, 0xbf040f37,
	0x1b80, 0x54c10f45,
	0x1b80, 0x54c10f47,
	0x1b80, 0x54a30f55,
	0x1b80, 0x54a30f57,
	0x1b80, 0xbf010f65,
	0x1b80, 0xbf010f67,
	0x1b80, 0xe13f0f75,
	0x1b80, 0xe13f0f77,
	0x1b80, 0x54c70f85,
	0x1b80, 0x54c70f87,
	0x1b80, 0x00010f95,
	0x1b80, 0x00010f97,
	0x1b80, 0x54a70fa5,
	0x1b80, 0x54a70fa7,
	0x1b80, 0x54e50fb5,
	0x1b80, 0x54e50fb7,
	0x1b80, 0x050a0fc5,
	0x1b80, 0x050a0fc7,
	0x1b80, 0x54c70fd5,
	0x1b80, 0x54c70fd7,
	0x1b80, 0x00010fe5,
	0x1b80, 0x00010fe7,
	0x1b80, 0x5b400ff5,
	0x1b80, 0x5b400ff7,
	0x1b80, 0x73811005,
	0x1b80, 0x73811007,
	0x1b80, 0x7f201015,
	0x1b80, 0x7f201017,
	0x1b80, 0x7e001025,
	0x1b80, 0x7e001027,
	0x1b80, 0x7d001035,
	0x1b80, 0x7d001037,
	0x1b80, 0x5b401045,
	0x1b80, 0x5b401047,
	0x1b80, 0x55011055,
	0x1b80, 0x55011057,
	0x1b80, 0x5c011065,
	0x1b80, 0x5c011067,
	0x1b80, 0xe0c71075,
	0x1b80, 0xe0c71077,
	0x1b80, 0x54801085,
	0x1b80, 0x54801087,
	0x1b80, 0x54001095,
	0x1b80, 0x54001097,
	0x1b80, 0x548110a5,
	0x1b80, 0x548110a7,
	0x1b80, 0x540010b5,
	0x1b80, 0x540010b7,
	0x1b80, 0x548210c5,
	0x1b80, 0x548210c7,
	0x1b80, 0x540010d5,
	0x1b80, 0x540010d7,
	0x1b80, 0x548510e5,
	0x1b80, 0x548510e7,
	0x1b80, 0x540010f5,
	0x1b80, 0x540010f7,
	0x1b80, 0x73011105,
	0x1b80, 0x73011107,
	0x1b80, 0xe0ea1115,
	0x1b80, 0xe0ea1117,
	0x1b80, 0xbfe81125,
	0x1b80, 0xbfe81127,
	0x1b80, 0x301f1135,
	0x1b80, 0x301f1137,
	0x1b80, 0x56111145,
	0x1b80, 0x56111147,
	0x1b80, 0x56011155,
	0x1b80, 0x56011157,
	0x1b80, 0x8c001165,
	0x1b80, 0x8c001167,
	0x1b80, 0x00011175,
	0x1b80, 0x00011177,
	0x1b80, 0x72801185,
	0x1b80, 0x72801187,
	0x1b80, 0x72001195,
	0x1b80, 0x72001197,
	0x1b80, 0x920011a5,
	0x1b80, 0x920011a7,
	0x1b80, 0x000111b5,
	0x1b80, 0x000111b7,
	0x1b80, 0x738911c5,
	0x1b80, 0x738911c7,
	0x1b80, 0x730911d5,
	0x1b80, 0x730911d7,
	0x1b80, 0x910011e5,
	0x1b80, 0x910011e7,
	0x1b80, 0x000111f5,
	0x1b80, 0x000111f7,
	0x1b80, 0x00071205,
	0x1b80, 0x00071207,
	0x1b80, 0x75801215,
	0x1b80, 0x75801217,
	0x1b80, 0x00041225,
	0x1b80, 0x00041227,
	0x1b80, 0x4d081235,
	0x1b80, 0x4d081237,
	0x1b80, 0x57101245,
	0x1b80, 0x57101247,
	0x1b80, 0x57001255,
	0x1b80, 0x57001257,
	0x1b80, 0x4d001265,
	0x1b80, 0x4d001267,
	0x1b80, 0x00071275,
	0x1b80, 0x00071277,
	0x1b80, 0x75001285,
	0x1b80, 0x75001287,
	0x1b80, 0x00011295,
	0x1b80, 0x00011297,
	0x1b80, 0x002f12a5,
	0x1b80, 0x002f12a7,
	0x1b80, 0x000012b5,
	0x1b80, 0x000012b7,
	0x1b80, 0x000212c5,
	0x1b80, 0x000212c7,
	0x1b80, 0x000112d5,
	0x1b80, 0x000112d7,
	0x1b80, 0x548712e5,
	0x1b80, 0x548712e7,
	0x1b80, 0x540012f5,
	0x1b80, 0x540012f7,
	0x1b80, 0x5c011305,
	0x1b80, 0x5c011307,
	0x1b80, 0x54c71315,
	0x1b80, 0x54c71317,
	0x1b80, 0x54001325,
	0x1b80, 0x54001327,
	0x1b80, 0x5c021335,
	0x1b80, 0x5c021337,
	0x1b80, 0x00011345,
	0x1b80, 0x00011347,
	0x1b80, 0x5c011355,
	0x1b80, 0x5c011357,
	0x1b80, 0x07141365,
	0x1b80, 0x07141367,
	0x1b80, 0x54001375,
	0x1b80, 0x54001377,
	0x1b80, 0x5c021385,
	0x1b80, 0x5c021387,
	0x1b80, 0x00011395,
	0x1b80, 0x00011397,
	0x1b80, 0x5c0213a5,
	0x1b80, 0x5c0213a7,
	0x1b80, 0x071413b5,
	0x1b80, 0x071413b7,
	0x1b80, 0x540013c5,
	0x1b80, 0x540013c7,
	0x1b80, 0x5c0113d5,
	0x1b80, 0x5c0113d7,
	0x1b80, 0x000113e5,
	0x1b80, 0x000113e7,
	0x1b80, 0x4c9813f5,
	0x1b80, 0x4c9813f7,
	0x1b80, 0x4c181405,
	0x1b80, 0x4c181407,
	0x1b80, 0x00011415,
	0x1b80, 0x00011417,
	0x1b80, 0x00001425,
	0x1b80, 0x00001427,
	0x1b80, 0x00001435,
	0x1b80, 0x00001437,
	0x1b80, 0x00001445,
	0x1b80, 0x00001447,
	0x1b80, 0x00001455,
	0x1b80, 0x00001457,
	0x1b80, 0x00001465,
	0x1b80, 0x00001467,
	0x1b80, 0x00001475,
	0x1b80, 0x00001477,
	0x1b80, 0x00001485,
	0x1b80, 0x00001487,
	0x1b80, 0x00001495,
	0x1b80, 0x00001497,
	0x1b80, 0x000114a5,
	0x1b80, 0x000114a7,
	0x1b80, 0x000414b5,
	0x1b80, 0x000414b7,
	0x1b80, 0x5c0214c5,
	0x1b80, 0x5c0214c7,
	0x1b80, 0x620414d5,
	0x1b80, 0x620414d7,
	0x1b80, 0x660714e5,
	0x1b80, 0x660714e7,
	0x1b80, 0x4d0c14f5,
	0x1b80, 0x4d0c14f7,
	0x1b80, 0x09011505,
	0x1b80, 0x09011507,
	0x1b80, 0x0c011515,
	0x1b80, 0x0c011517,
	0x1b80, 0x0ba61525,
	0x1b80, 0x0ba61527,
	0x1b80, 0x00011535,
	0x1b80, 0x00011537,
	0x1b80, 0x00000006,
	0x1b80, 0x00000002,
};

void odm_read_and_config_mp_8733b_cal_init(void *dm_void)
{
	struct dm_struct *dm = (struct dm_struct *)dm_void;
	struct dm_dpk_info *dpk_info = &dm->dpk_info;

	u32	i = 0;
	u32	array_len = sizeof(array_mp_8733b_cal_init) / sizeof(u32);
	u32	*array = array_mp_8733b_cal_init;
	u32	v1 = 0, v2 = 0;

	while ((i + 1) < array_len) {
		v1 = array[i];
		v2 = array[i + 1];
		odm_config_bb_phy_8733b(dm, v1, MASKDWORD, v2);
		RF_DBG(dm, DBG_RF_INIT, "v1 = 0x%x, v2 = 0x%x\n", v1, v2);
		i = i + 2;
	}

	dpk_info->is_dpk_pwr_on = 1;
	dpk_info->is_dpk_enable = 1;
	dpk_info->is_dpk_by_channel = 1;
}

#endif