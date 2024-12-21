#ifndef _SND_SOC_CODEC_TAS5805M_BURST_H_
#define _SND_SOC_CODEC_TAS5805M_BURST_H_

struct cfg_reg {
	unsigned char command;
	unsigned char param;
};

#define CFG_META_SWITCH (255)
#define CFG_META_DELAY  (254)
#define CFG_META_BURST  (253)

static const struct cfg_reg tas5805m_init_regs_1[] = {
//RESET
    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x03, 0x02 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x01, 0x11 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x46, 0x01 },

    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x03, 0x02 },
    { CFG_META_DELAY, 5 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x74, 0x10 },
    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x78, 0x80 },

    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x61, 0x0b },
    { 0x60, 0x01 },
    { CFG_META_BURST, 3 },
    { 0x7d, 0x11 },
    { 0xff, 0x00 },
    { 0x00, 0x01 },
    { 0x51, 0x05 },


    { 0x00, 0x00 },
    { 0x02, 0x04 },
    { 0x53, 0x00 },
    { 0x54, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },

    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x66, 0x84 },
    { 0x7f, 0x8c },
    { 0x00, 0x29 },
    { CFG_META_BURST, 17 },
    { 0x18, 0x00 },
    { 0x40, 0x26 },
    { 0xe7, 0x00 },
    { 0x40, 0x26 },
    { 0xe7, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x2a },
    { CFG_META_BURST, 9 },
    { 0x24, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 5 },
    { 0x30, 0x00 },
    { 0x71, 0x94 },
    { 0x9a, 0x00 },
    { 0x00, 0x2c },
    { CFG_META_BURST, 25 },
    { 0x0c, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 9 },
    { 0x28, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 9 },
    { 0x34, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 9 },
    { 0x48, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 21 },
    { 0x5c, 0x00 },
    { 0x00, 0x3d },
    { 0x2b, 0x00 },
    { 0x04, 0x92 },
    { 0xe9, 0x00 },
    { 0xce, 0xc0 },
    { 0x8a, 0xc0 },
    { 0x00, 0x00 },
    { 0x00, 0x02 },
    { 0x96, 0x7e },
    { 0x0c, 0x00 },
    { CFG_META_BURST, 5 },
    { 0x74, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x2d },
    { CFG_META_BURST, 25 },
    { 0x18, 0x7d },
    { 0x69, 0x81 },
    { 0xf4, 0x00 },
    { 0x00, 0x57 },
    { 0x62, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x2e },
    { CFG_META_BURST, 5 },
    { 0x24, 0x11 },
    { 0x3d, 0xc3 },
    { 0x1a, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0xaa },
    { 0x00, 0x24 },
    { CFG_META_BURST, 105 },
    { 0x18, 0x02 },
    { 0xd4, 0xfa },
    { 0x70, 0xfa },
    { 0x56, 0x0b },
    { 0x1f, 0x02 },
    { 0xd4, 0xfa },
    { 0x70, 0x0f },
    { 0xf6, 0x85 },
    { 0x99, 0xf8 },
    { 0x09, 0x74 },
    { 0xcd, 0x07 },
    { 0xfb, 0x44 },
    { 0x33, 0xf0 },
    { 0x09, 0x77 },
    { 0x9a, 0x07 },
    { 0xfb, 0x44 },
    { 0x33, 0x0f },
    { 0xf6, 0x85 },
    { 0x99, 0xf8 },
    { 0x09, 0x74 },
    { 0xcd, 0x08 },
    { 0x07, 0x80 },
    { 0x33, 0xf0 },
    { 0x05, 0x14 },
    { 0xe1, 0x07 },
    { 0xf3, 0x77 },
    { 0x8a, 0x0f },
    { 0xfa, 0xeb },
    { 0x1f, 0xf8 },
    { 0x05, 0x08 },
    { 0x43, 0x07 },
    { 0xfb, 0x09 },
    { 0x31, 0xf0 },
    { 0x0a, 0x0b },
    { 0xd3, 0x07 },
    { 0xfa, 0xef },
    { 0x85, 0x0f },
    { 0xf5, 0xf4 },
    { 0x2d, 0xf8 },
    { 0x0a, 0x07 },
    { 0x4a, 0x05 },
    { 0x60, 0xa6 },
    { 0x26, 0xf8 },
    { 0x88, 0x81 },
    { 0xbc, 0x02 },
    { 0xdf, 0x40 },
    { 0xb5, 0x0c },
    { 0x10, 0x1f },
    { 0x14, 0xfb },
    { 0x27, 0x78 },
    { 0x55, 0x07 },
    { 0xe4, 0x63 },
    { 0x0b, 0x00 },
    { 0x00, 0x25 },
    { CFG_META_BURST, 121 },
    { 0x08, 0xf0 },
    { 0xf1, 0x47 },
    { 0x6c, 0x07 },
    { 0x5e, 0x84 },
    { 0x71, 0x0f },
    { 0x0e, 0xb8 },
    { 0x94, 0xf8 },
    { 0xbd, 0x18 },
    { 0x84, 0x05 },
    { 0xb3, 0x44 },
    { 0xb4, 0xf5 },
    { 0x10, 0x4d },
    { 0x12, 0x05 },
    { 0x40, 0xff },
    { 0x61, 0x0f },
    { 0x73, 0x9f },
    { 0x35, 0xf8 },
    { 0x87, 0xcf },
    { 0xa4, 0x07 },
    { 0xfc, 0x1b },
    { 0x0d, 0xf0 },
    { 0x12, 0x57 },
    { 0x98, 0x07 },
    { 0xf2, 0x19 },
    { 0x1d, 0x0f },
    { 0xed, 0xa8 },
    { 0x68, 0xf8 },
    { 0x11, 0xcb },
    { 0xd6, 0x08 },
    { 0x82, 0x31 },
    { 0x37, 0xf9 },
    { 0x3b, 0x96 },
    { 0xbd, 0x05 },
    { 0x06, 0xa1 },
    { 0x4f, 0x06 },
    { 0xc4, 0x69 },
    { 0x43, 0xfa },
    { 0x77, 0x2d },
    { 0x7b, 0x07 },
    { 0xf9, 0xe7 },
    { 0xe4, 0xf0 },
    { 0x40, 0xcb },
    { 0x20, 0x07 },
    { 0xca, 0xd5 },
    { 0x3b, 0x0f },
    { 0xbf, 0x34 },
    { 0xe0, 0xf8 },
    { 0x3b, 0x42 },
    { 0xe1, 0x08 },
    { 0x03, 0xe6 },
    { 0xe3, 0xf0 },
    { 0x0a, 0x19 },
    { 0x10, 0x07 },
    { 0xf2, 0x12 },
    { 0x32, 0x0f },
    { 0xf5, 0xe6 },
    { 0xf0, 0xf8 },
    { 0x0a, 0x06 },
    { 0xea, 0x07 },
    { 0xff, 0x0b },
    { 0xf9, 0x00 },
    { 0x00, 0x26 },
    { CFG_META_BURST, 121 },
    { 0x08, 0xf0 },
    { 0x02, 0x20 },
    { 0x4d, 0x07 },
    { 0xfe, 0xd5 },
    { 0xbf, 0x0f },
    { 0xfd, 0xdf },
    { 0xb3, 0xf8 },
    { 0x02, 0x1e },
    { 0x48, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x02 },
    { 0xc4, 0x79 },
    { 0xcb, 0xfa },
    { 0x77, 0x0c },
    { 0x6a, 0x02 },
    { 0xc4, 0x79 },
    { 0xcb, 0x0f },
    { 0xf6, 0x85 },
    { 0x99, 0xf8 },
    { 0x09, 0x74 },
    { 0xcd, 0x07 },
    { 0xfb, 0x44 },
    { 0x33, 0xf0 },
    { 0x09, 0x77 },
    { 0x9a, 0x07 },
    { 0xfb, 0x44 },
    { 0x33, 0x0f },
    { 0xf6, 0x85 },
    { 0x99, 0xf8 },
    { 0x09, 0x74 },
    { 0xcd, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x27 },
    { CFG_META_BURST, 121 },
    { 0x08, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x08 },
    { 0x0c, 0x93 },
    { 0xf7, 0xf0 },
    { 0x04, 0xcb },
    { 0x3f, 0x07 },
    { 0xee, 0xaf },
    { 0x25, 0x0f },
    { 0xfb, 0x34 },
    { 0xc1, 0xf8 },
    { 0x04, 0xbc },
    { 0xe4, 0x07 },
    { 0xf2, 0x53 },
    { 0x0a, 0xf0 },
    { 0x3d, 0xd7 },
    { 0x79, 0x07 },
    { 0xd6, 0xd7 },
    { 0xc9, 0x0f },
    { 0xc2, 0x28 },
    { 0x87, 0xf8 },
    { 0x36, 0xd5 },
    { 0x2e, 0x07 },
    { 0xd0, 0x05 },
    { 0x62, 0xf1 },
    { 0x25, 0xbe },
    { 0x57, 0x07 },
    { 0x54, 0xb9 },
    { 0xdf, 0x0e },
    { 0xda, 0x41 },
    { 0xa9, 0xf8 },
    { 0xdb, 0x40 },
    { 0xbf, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x01 },
    { 0xc2, 0xf5 },
    { 0x70, 0x03 },
    { 0x85, 0xea },
    { 0xe1, 0x01 },
    { 0xc2, 0xf5 },
    { 0x70, 0x02 },
    { 0x75, 0xe5 },
    { 0x5a, 0xfe },
    { 0x7e, 0x44 },
    { 0xe4, 0x07 },
    { 0xfc, 0x46 },
    { 0x4f, 0x00 },
    { 0x00, 0x28 },
    { CFG_META_BURST, 121 },
    { 0x08, 0xf0 },
    { 0x07, 0x8b },
    { 0x2f, 0x07 },
    { 0xfc, 0x33 },
    { 0x0b, 0x0f },
    { 0xf8, 0x74 },
    { 0xd1, 0xf8 },
    { 0x07, 0x86 },
    { 0xa5, 0x07 },
    { 0xb1, 0x18 },
    { 0x26, 0xf4 },
    { 0x15, 0xdb },
    { 0x41, 0x06 },
    { 0xa3, 0x48 },
    { 0x39, 0x0b },
    { 0xea, 0x24 },
    { 0xbf, 0xf9 },
    { 0xab, 0x9f },
    { 0xa1, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x09 },
    { 0x6e, 0x24 },
    { 0x4a, 0xf9 },
    { 0x6f, 0xe2 },
    { 0x7a, 0x03 },
    { 0xb2, 0x16 },
    { 0xc2, 0x06 },
    { 0x90, 0x1d },
    { 0x86, 0xfa },
    { 0xdf, 0xc4 },
    { 0xf4, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x08 },
    { 0x43, 0x92 },
    { 0x06, 0x00 },
    { 0x00, 0x29 },
    { CFG_META_BURST, 17 },
    { 0x08, 0xf1 },
    { 0xc7, 0xfd },
    { 0x6c, 0x06 },
    { 0x74, 0xd8 },
    { 0x67, 0x0e },
    { 0x38, 0x02 },
    { 0x94, 0xf9 },
    { 0x47, 0x95 },
    { 0x93, 0x00 },
    { 0x00, 0x2e },
    { CFG_META_BURST, 5 },
    { 0x7c, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x2f },
    { CFG_META_BURST, 17 },
    { 0x08, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 21 },
    { 0x1c, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x2a },
    { CFG_META_BURST, 21 },
    { 0x48, 0x00 },
    { 0x02, 0x2b },
    { 0x09, 0x00 },
    { 0x02, 0x2b },
    { 0x09, 0x00 },
    { 0x02, 0x2b },
    { 0x09, 0x7e },
    { 0x84, 0xe3 },
    { 0xfe, 0x82 },
    { 0xed, 0x8b },
    { 0xdc, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x2b },
    { CFG_META_BURST, 41 },
    { 0x34, 0x00 },
    { 0x44, 0x32 },
    { 0x13, 0x00 },
    { 0x22, 0x1d },
    { 0x95, 0x00 },
    { 0x01, 0x23 },
    { 0x44, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0xff },
    { 0x81, 0x47 },
    { 0xae, 0xf9 },
    { 0xda, 0xbc },
    { 0x21, 0xfc },
    { 0x2e, 0x06 },
    { 0x3e, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x2d },
    { CFG_META_BURST, 41 },
    { 0x58, 0x00 },
    { 0x03, 0x69 },
    { 0xc5, 0x00 },
    { 0x22, 0x1d },
    { 0x95, 0x00 },
    { 0x00, 0x57 },
    { 0x62, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0xff },
    { 0x81, 0x47 },
    { 0xae, 0xf9 },
    { 0xda, 0xbc },
    { 0x21, 0xfc },
    { 0x58, 0x8b },
    { 0x89, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0xaa },
    { 0x00, 0x2e },
    { CFG_META_BURST, 21 },
    { 0x40, 0x13 },
    { 0xd8, 0xb6 },
    { 0x46, 0x13 },
    { 0xd8, 0xb6 },
    { 0x46, 0x13 },
    { 0xd8, 0xb6 },
    { 0x46, 0x27 },
    { 0xb1, 0x6c },
    { 0x8c, 0xe1 },
    { 0x3a, 0x4d },
    { 0xcd, 0x00 },
    { 0x00, 0x2b },
    { CFG_META_BURST, 21 },
    { 0x20, 0x3b },
    { 0x8a, 0x22 },
    { 0xd3, 0xc4 },
    { 0x75, 0xdd },
    { 0x2d, 0x3b },
    { 0x8a, 0x22 },
    { 0xd3, 0x27 },
    { 0xb1, 0x6c },
    { 0x8c, 0xe1 },
    { 0x3a, 0x4d },
    { 0xcd, 0x00 },
    { CFG_META_BURST, 21 },
    { 0x0c, 0x3b },
    { 0x8a, 0x22 },
    { 0xd3, 0xc4 },
    { 0x75, 0xdd },
    { 0x2d, 0x3b },
    { 0x8a, 0x22 },
    { 0xd3, 0x27 },
    { 0xb1, 0x6c },
    { 0x8c, 0xe1 },
    { 0x3a, 0x4d },
    { 0xcd, 0x00 },
    { 0x00, 0x2a },
    { CFG_META_BURST, 21 },
    { 0x34, 0x00 },
    { 0x02, 0x2b },
    { 0x09, 0x00 },
    { 0x02, 0x2b },
    { 0x09, 0x00 },
    { 0x02, 0x2b },
    { 0x09, 0x7e },
    { 0x84, 0xe3 },
    { 0xfe, 0x82 },
    { 0xed, 0x8b },
    { 0xdc, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x2d },
    { CFG_META_BURST, 41 },
    { 0x30, 0x00 },
    { 0x44, 0x32 },
    { 0x13, 0x00 },
    { 0x22, 0x1d },
    { 0x95, 0x00 },
    { 0x01, 0x23 },
    { 0x44, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0xff },
    { 0x81, 0x47 },
    { 0xae, 0xf9 },
    { 0xda, 0xbc },
    { 0x21, 0xfc },
    { 0x58, 0x8b },
    { 0x89, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0xaa },
    { 0x00, 0x2a },
    { CFG_META_BURST, 37 },
    { 0x5c, 0x7e },
    { 0x87, 0x0f },
    { 0x08, 0x81 },
    { 0x78, 0xf0 },
    { 0xf8, 0x7e },
    { 0x87, 0x0f },
    { 0x08, 0x7e },
    { 0x84, 0xe3 },
    { 0xfe, 0x82 },
    { 0xed, 0x8b },
    { 0xdc, 0x7e },
    { 0x87, 0x0f },
    { 0x08, 0x81 },
    { 0x78, 0xf0 },
    { 0xf8, 0x7e },
    { 0x87, 0x0f },
    { 0x08, 0x7e },
    { 0x84, 0xe3 },
    { 0xfe, 0x00 },
    { 0x00, 0x2b },
    { CFG_META_BURST, 5 },
    { 0x08, 0x82 },
    { 0xed, 0x8b },
    { 0xdc, 0x00 },
    { 0x00, 0x2e },
    { CFG_META_BURST, 21 },
    { 0x54, 0x13 },
    { 0xd8, 0xb6 },
    { 0x46, 0x13 },
    { 0xd8, 0xb6 },
    { 0x46, 0x13 },
    { 0xd8, 0xb6 },
    { 0x46, 0x27 },
    { 0xb1, 0x6c },
    { 0x8c, 0xe1 },
    { 0x3a, 0x4d },
    { 0xcd, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x2e },
    { CFG_META_BURST, 5 },
    { 0x10, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 5 },
    { 0x0c, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 5 },
    { 0x08, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 13 },
    { 0x18, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x40 },
    { 0x00, 0x00 },
    { 0x00, 0x40 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
//Register Tuning
    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x30, 0x00 },
    { 0x4c, 0x22 },
    { 0x03, 0x03 },

    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x78, 0x80 },
};

static const struct cfg_reg tas5805m_init_regs_2[] = {
//RESET
    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x03, 0x02 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x01, 0x11 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x46, 0x01 },

    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x03, 0x02 },
    { CFG_META_DELAY, 5 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x74, 0x10 },
    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x78, 0x80 },

    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x61, 0x0b },
    { 0x60, 0x01 },
    { CFG_META_BURST, 3 },
    { 0x7d, 0x11 },
    { 0xff, 0x00 },
    { 0x00, 0x01 },
    { 0x51, 0x05 },


    { 0x00, 0x00 },
    { 0x02, 0x04 },
    { 0x53, 0x00 },
    { 0x54, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },

    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x66, 0x84 },
    { 0x7f, 0x8c },
    { 0x00, 0x29 },
    { CFG_META_BURST, 17 },
    { 0x18, 0x00 },
    { 0x40, 0x26 },
    { 0xe7, 0x00 },
    { 0x40, 0x26 },
    { 0xe7, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x2a },
    { CFG_META_BURST, 9 },
    { 0x24, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 5 },
    { 0x30, 0x00 },
    { 0x71, 0x94 },
    { 0x9a, 0x00 },
    { 0x00, 0x2c },
    { CFG_META_BURST, 25 },
    { 0x0c, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 9 },
    { 0x28, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 9 },
    { 0x34, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 9 },
    { 0x48, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 21 },
    { 0x5c, 0x00 },
    { 0x00, 0x57 },
    { 0x62, 0x00 },
    { 0x01, 0x5d },
    { 0x86, 0x00 },
    { 0xfe, 0x5c },
    { 0x54, 0xc0 },
    { 0x00, 0x00 },
    { 0x00, 0x02 },
    { 0x96, 0x7e },
    { 0x0c, 0x00 },
    { CFG_META_BURST, 5 },
    { 0x74, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x2d },
    { CFG_META_BURST, 25 },
    { 0x18, 0x7d },
    { 0x69, 0x81 },
    { 0xf4, 0x00 },
    { 0x00, 0x57 },
    { 0x62, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x2e },
    { CFG_META_BURST, 5 },
    { 0x24, 0x11 },
    { 0x3d, 0xc3 },
    { 0x1a, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0xaa },
    { 0x00, 0x24 },
    { CFG_META_BURST, 105 },
    { 0x18, 0x02 },
    { 0x32, 0xc3 },
    { 0x26, 0xfb },
    { 0x9a, 0x79 },
    { 0xb4, 0x02 },
    { 0x32, 0xc3 },
    { 0x26, 0x0f },
    { 0xf6, 0x85 },
    { 0x99, 0xf8 },
    { 0x09, 0x74 },
    { 0xcd, 0x07 },
    { 0xfb, 0x44 },
    { 0x33, 0xf0 },
    { 0x09, 0x77 },
    { 0x9a, 0x07 },
    { 0xfb, 0x44 },
    { 0x33, 0x0f },
    { 0xf6, 0x85 },
    { 0x99, 0xf8 },
    { 0x09, 0x74 },
    { 0xcd, 0x07 },
    { 0xfe, 0x25 },
    { 0x4d, 0xf0 },
    { 0x07, 0xc6 },
    { 0x0f, 0x07 },
    { 0xfa, 0x6b },
    { 0x61, 0x0f },
    { 0xf8, 0x39 },
    { 0xf1, 0xf8 },
    { 0x07, 0x6f },
    { 0x52, 0x08 },
    { 0x0b, 0x99 },
    { 0xc8, 0xf0 },
    { 0x05, 0x13 },
    { 0x07, 0x07 },
    { 0xef, 0x61 },
    { 0x8d, 0x0f },
    { 0xfa, 0xec },
    { 0xf9, 0xf8 },
    { 0x05, 0x04 },
    { 0xac, 0x07 },
    { 0xf8, 0x32 },
    { 0x9a, 0xf0 },
    { 0x3b, 0xaf },
    { 0x56, 0x07 },
    { 0xd2, 0x5f },
    { 0x22, 0x0f },
    { 0xc4, 0x50 },
    { 0xaa, 0xf8 },
    { 0x35, 0x6e },
    { 0x43, 0x07 },
    { 0xfd, 0x70 },
    { 0x3d, 0x00 },
    { 0x00, 0x25 },
    { CFG_META_BURST, 121 },
    { 0x08, 0xf0 },
    { 0x1b, 0x16 },
    { 0xc6, 0x07 },
    { 0xe9, 0xa6 },
    { 0xfe, 0x0f },
    { 0xe4, 0xe9 },
    { 0x3a, 0xf8 },
    { 0x18, 0xe8 },
    { 0xc5, 0x07 },
    { 0xe3, 0xc1 },
    { 0x03, 0xf0 },
    { 0x8e, 0x69 },
    { 0xac, 0x07 },
    { 0xaa, 0xfe },
    { 0x31, 0x0f },
    { 0x71, 0x96 },
    { 0x54, 0xf8 },
    { 0x71, 0x40 },
    { 0xcb, 0x01 },
    { 0xc2, 0xf5 },
    { 0x70, 0x03 },
    { 0x85, 0xea },
    { 0xe1, 0x01 },
    { 0xc2, 0xf5 },
    { 0x70, 0x02 },
    { 0x75, 0xe5 },
    { 0x5a, 0xfe },
    { 0x7e, 0x44 },
    { 0xe4, 0x07 },
    { 0xfc, 0x46 },
    { 0x4f, 0xf0 },
    { 0x07, 0x8b },
    { 0x2f, 0x07 },
    { 0xfc, 0x33 },
    { 0x0b, 0x0f },
    { 0xf8, 0x74 },
    { 0xd1, 0xf8 },
    { 0x07, 0x86 },
    { 0xa5, 0x08 },
    { 0x1b, 0xc1 },
    { 0xca, 0xf1 },
    { 0x68, 0xa9 },
    { 0xdd, 0x07 },
    { 0x85, 0x54 },
    { 0x78, 0x0e },
    { 0x97, 0x56 },
    { 0x23, 0xf8 },
    { 0x5e, 0xe9 },
    { 0xbd, 0x08 },
    { 0x33, 0x2b },
    { 0x14, 0xf2 },
    { 0x1c, 0x56 },
    { 0xf9, 0x07 },
    { 0x49, 0x57 },
    { 0x49, 0x0d },
    { 0xe3, 0xa9 },
    { 0x07, 0xf8 },
    { 0x83, 0x7d },
    { 0xa3, 0x07 },
    { 0xef, 0x27 },
    { 0x16, 0x00 },
    { 0x00, 0x26 },
    { CFG_META_BURST, 121 },
    { 0x08, 0xf0 },
    { 0xbf, 0xdb },
    { 0x9d, 0x07 },
    { 0x9d, 0x79 },
    { 0xe3, 0x0f },
    { 0x40, 0x24 },
    { 0x63, 0xf8 },
    { 0x73, 0x5f },
    { 0x07, 0x08 },
    { 0x82, 0x31 },
    { 0x37, 0xf9 },
    { 0x3b, 0x96 },
    { 0xbd, 0x05 },
    { 0x06, 0xa1 },
    { 0x4f, 0x06 },
    { 0xc4, 0x69 },
    { 0x43, 0xfa },
    { 0x77, 0x2d },
    { 0x7b, 0x07 },
    { 0xda, 0x12 },
    { 0x77, 0xf5 },
    { 0x10, 0x0b },
    { 0xaa, 0x07 },
    { 0x22, 0x32 },
    { 0x3a, 0x0a },
    { 0xef, 0xf4 },
    { 0x56, 0xf9 },
    { 0x03, 0xbb },
    { 0x4e, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x02 },
    { 0xc4, 0x79 },
    { 0xcb, 0xfa },
    { 0x77, 0x0c },
    { 0x6a, 0x02 },
    { 0xc4, 0x79 },
    { 0xcb, 0x0f },
    { 0xf6, 0x85 },
    { 0x99, 0xf8 },
    { 0x09, 0x74 },
    { 0xcd, 0x07 },
    { 0xfb, 0x44 },
    { 0x33, 0xf0 },
    { 0x09, 0x77 },
    { 0x9a, 0x07 },
    { 0xfb, 0x44 },
    { 0x33, 0x0f },
    { 0xf6, 0x85 },
    { 0x99, 0xf8 },
    { 0x09, 0x74 },
    { 0xcd, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x27 },
    { CFG_META_BURST, 121 },
    { 0x08, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x08 },
    { 0x0c, 0x93 },
    { 0xf7, 0xf0 },
    { 0x04, 0xcb },
    { 0x3f, 0x07 },
    { 0xee, 0xaf },
    { 0x25, 0x0f },
    { 0xfb, 0x34 },
    { 0xc1, 0xf8 },
    { 0x04, 0xbc },
    { 0xe4, 0x07 },
    { 0xf2, 0x53 },
    { 0x0a, 0xf0 },
    { 0x3d, 0xd7 },
    { 0x79, 0x07 },
    { 0xd6, 0xd7 },
    { 0xc9, 0x0f },
    { 0xc2, 0x28 },
    { 0x87, 0xf8 },
    { 0x36, 0xd5 },
    { 0x2e, 0x07 },
    { 0xd0, 0x05 },
    { 0x62, 0xf1 },
    { 0x25, 0xbe },
    { 0x57, 0x07 },
    { 0x54, 0xb9 },
    { 0xdf, 0x0e },
    { 0xda, 0x41 },
    { 0xa9, 0xf8 },
    { 0xdb, 0x40 },
    { 0xbf, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x01 },
    { 0xc2, 0xf5 },
    { 0x70, 0x03 },
    { 0x85, 0xea },
    { 0xe1, 0x01 },
    { 0xc2, 0xf5 },
    { 0x70, 0x02 },
    { 0x75, 0xe5 },
    { 0x5a, 0xfe },
    { 0x7e, 0x44 },
    { 0xe4, 0x07 },
    { 0xfc, 0x46 },
    { 0x4f, 0x00 },
    { 0x00, 0x28 },
    { CFG_META_BURST, 121 },
    { 0x08, 0xf0 },
    { 0x07, 0x8b },
    { 0x2f, 0x07 },
    { 0xfc, 0x33 },
    { 0x0b, 0x0f },
    { 0xf8, 0x74 },
    { 0xd1, 0xf8 },
    { 0x07, 0x86 },
    { 0xa5, 0x07 },
    { 0xb1, 0x18 },
    { 0x26, 0xf4 },
    { 0x15, 0xdb },
    { 0x41, 0x06 },
    { 0xa3, 0x48 },
    { 0x39, 0x0b },
    { 0xea, 0x24 },
    { 0xbf, 0xf9 },
    { 0xab, 0x9f },
    { 0xa1, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x09 },
    { 0x6e, 0x24 },
    { 0x4a, 0xf9 },
    { 0x6f, 0xe2 },
    { 0x7a, 0x03 },
    { 0xb2, 0x16 },
    { 0xc2, 0x06 },
    { 0x90, 0x1d },
    { 0x86, 0xfa },
    { 0xdf, 0xc4 },
    { 0xf4, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x08 },
    { 0x43, 0x92 },
    { 0x06, 0x00 },
    { 0x00, 0x29 },
    { CFG_META_BURST, 17 },
    { 0x08, 0xf1 },
    { 0xc7, 0xfd },
    { 0x6c, 0x06 },
    { 0x74, 0xd8 },
    { 0x67, 0x0e },
    { 0x38, 0x02 },
    { 0x94, 0xf9 },
    { 0x47, 0x95 },
    { 0x93, 0x00 },
    { 0x00, 0x2e },
    { CFG_META_BURST, 5 },
    { 0x7c, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x2f },
    { CFG_META_BURST, 17 },
    { 0x08, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 21 },
    { 0x1c, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x2a },
    { CFG_META_BURST, 21 },
    { 0x48, 0x00 },
    { 0x01, 0x64 },
    { 0x0a, 0x00 },
    { 0x01, 0x64 },
    { 0x0a, 0x00 },
    { 0x01, 0x64 },
    { 0x0a, 0x7e },
    { 0xd0, 0xb5 },
    { 0x2d, 0x82 },
    { 0x59, 0x05 },
    { 0x7b, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x2b },
    { CFG_META_BURST, 41 },
    { 0x34, 0x01 },
    { 0x53, 0x8f },
    { 0xcc, 0x00 },
    { 0x2a, 0xa3 },
    { 0x8f, 0x00 },
    { 0x00, 0x6d },
    { 0x3a, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0xff },
    { 0x81, 0x47 },
    { 0xae, 0xf9 },
    { 0xda, 0xbc },
    { 0x21, 0xfc },
    { 0x58, 0x8b },
    { 0x89, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x2d },
    { CFG_META_BURST, 41 },
    { 0x58, 0x00 },
    { 0x03, 0x69 },
    { 0xc5, 0x00 },
    { 0x01, 0x5d },
    { 0x85, 0x00 },
    { 0x01, 0xb4 },
    { 0xe5, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0xff },
    { 0x81, 0x47 },
    { 0xae, 0xf9 },
    { 0xda, 0xbc },
    { 0x21, 0xfc },
    { 0x58, 0x8b },
    { 0x89, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0xaa },
    { 0x00, 0x2e },
    { CFG_META_BURST, 21 },
    { 0x40, 0x13 },
    { 0xd8, 0xb6 },
    { 0x46, 0x13 },
    { 0xd8, 0xb6 },
    { 0x46, 0x13 },
    { 0xd8, 0xb6 },
    { 0x46, 0x27 },
    { 0xb1, 0x6c },
    { 0x8c, 0xe1 },
    { 0x3a, 0x4d },
    { 0xcd, 0x00 },
    { 0x00, 0x2b },
    { CFG_META_BURST, 21 },
    { 0x20, 0x3b },
    { 0x8a, 0x22 },
    { 0xd3, 0xc4 },
    { 0x75, 0xdd },
    { 0x2d, 0x3b },
    { 0x8a, 0x22 },
    { 0xd3, 0x27 },
    { 0xb1, 0x6c },
    { 0x8c, 0xe1 },
    { 0x3a, 0x4d },
    { 0xcd, 0x00 },
    { CFG_META_BURST, 21 },
    { 0x0c, 0x3b },
    { 0x8a, 0x22 },
    { 0xd3, 0xc4 },
    { 0x75, 0xdd },
    { 0x2d, 0x3b },
    { 0x8a, 0x22 },
    { 0xd3, 0x27 },
    { 0xb1, 0x6c },
    { 0x8c, 0xe1 },
    { 0x3a, 0x4d },
    { 0xcd, 0x00 },
    { 0x00, 0x2a },
    { CFG_META_BURST, 21 },
    { 0x34, 0x00 },
    { 0x01, 0x64 },
    { 0x0a, 0x00 },
    { 0x01, 0x64 },
    { 0x0a, 0x00 },
    { 0x01, 0x64 },
    { 0x0a, 0x7e },
    { 0xd0, 0xb5 },
    { 0x2d, 0x82 },
    { 0x59, 0x05 },
    { 0x7b, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x2d },
    { CFG_META_BURST, 41 },
    { 0x30, 0x01 },
    { 0x53, 0x8f },
    { 0xcc, 0x00 },
    { 0x2a, 0xa3 },
    { 0x8f, 0x00 },
    { 0x01, 0xb4 },
    { 0xe5, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0xff },
    { 0x81, 0x47 },
    { 0xae, 0xf9 },
    { 0xda, 0xbc },
    { 0x21, 0xfc },
    { 0x7e, 0xd0 },
    { 0x4d, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0xaa },
    { 0x00, 0x2a },
    { CFG_META_BURST, 37 },
    { 0x5c, 0x7e },
    { 0xd2, 0x19 },
    { 0x37, 0x81 },
    { 0x2d, 0xe6 },
    { 0xc9, 0x7e },
    { 0xd2, 0x19 },
    { 0x37, 0x7e },
    { 0xd0, 0xb5 },
    { 0x2d, 0x82 },
    { 0x59, 0x05 },
    { 0x7b, 0x7e },
    { 0xd2, 0x19 },
    { 0x37, 0x81 },
    { 0x2d, 0xe6 },
    { 0xc9, 0x7e },
    { 0xd2, 0x19 },
    { 0x37, 0x7e },
    { 0xd0, 0xb5 },
    { 0x2d, 0x00 },
    { 0x00, 0x2b },
    { CFG_META_BURST, 5 },
    { 0x08, 0x82 },
    { 0x59, 0x05 },
    { 0x7b, 0x00 },
    { 0x00, 0x2e },
    { CFG_META_BURST, 21 },
    { 0x54, 0x13 },
    { 0xd8, 0xb6 },
    { 0x46, 0x13 },
    { 0xd8, 0xb6 },
    { 0x46, 0x13 },
    { 0xd8, 0xb6 },
    { 0x46, 0x27 },
    { 0xb1, 0x6c },
    { 0x8c, 0xe1 },
    { 0x3a, 0x4d },
    { 0xcd, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x2e },
    { CFG_META_BURST, 5 },
    { 0x10, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 5 },
    { 0x0c, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 5 },
    { 0x08, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 13 },
    { 0x18, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x40 },
    { 0x00, 0x00 },
    { 0x00, 0x40 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
//Register Tuning
    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x30, 0x00 },
    { 0x4c, 0x27 },
    { 0x03, 0x03 },

    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x78, 0x80 },
};

#endif /* _SND_SOC_CODEC_TAS5805M_BURST_H_ */
