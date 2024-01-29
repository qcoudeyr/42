/*
 * "streamable kanji code filter and converter"
 * Copyright (c) 1998-2002 HappySize, Inc. All rights reserved.
 *
 * LICENSE NOTICES
 *
 * This file is part of "streamable kanji code filter and converter",
 * which is distributed under the terms of GNU Lesser General Public
 * License (version 2) as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with "streamable kanji code filter and converter";
 * if not, write to the Free Software Foundation, Inc., 59 Temple Place,
 * Suite 330, Boston, MA  02111-1307  USA
 *
 * The author of this file: Rui Hirokawa <hirokawa@php.net>
 *
 */

#ifndef UNICODE_TABLE_CP932_EXT_H
#define UNICODE_TABLE_CP932_EXT_H

const unsigned short cp932ext1_ucs_table[] = {
 /* ku 13 */
 0x2460,0x2461,0x2462,0x2463,0x2464,0x2465,0x2466,0x2467,
 0x2468,0x2469,0x246A,0x246B,0x246C,0x246D,0x246E,0x246F,
 0x2470,0x2471,0x2472,0x2473,0x2160,0x2161,0x2162,0x2163,
 0x2164,0x2165,0x2166,0x2167,0x2168,0x2169,0x0000,0x3349,
 0x3314,0x3322,0x334D,0x3318,0x3327,0x3303,0x3336,0x3351,
 0x3357,0x330D,0x3326,0x3323,0x332B,0x334A,0x333B,0x339C,
 0x339D,0x339E,0x338E,0x338F,0x33C4,0x33A1,0x0000,0x0000,
 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x337B,0x301D,
 0x301F,0x2116,0x33CD,0x2121,0x32A4,0x32A5,0x32A6,0x32A7,
 0x32A8,0x3231,0x3232,0x3239,0x337E,0x337D,0x337C,0x2252,
 0x2261,0x222B,0x222E,0x2211,0x221A,0x22A5,0x2220,0x221F,
 0x22BF,0x2235,0x2229,0x222A,0x0000,0x0000
};
const int cp932ext1_ucs_table_min = (13 - 1)*94;
const int cp932ext1_ucs_table_max = (13 - 1)*94 + (sizeof (cp932ext1_ucs_table) / sizeof (unsigned short));

const unsigned short cp932ext2_ucs_table[] = {
 /* ku 89 */
 0x7E8A,0x891C,0x9348,0x9288,0x84DC,0x4FC9,0x70BB,0x6631,
 0x68C8,0x92F9,0x66FB,0x5F45,0x4E28,0x4EE1,0x4EFC,0x4F00,
 0x4F03,0x4F39,0x4F56,0x4F92,0x4F8A,0x4F9A,0x4F94,0x4FCD,
 0x5040,0x5022,0x4FFF,0x501E,0x5046,0x5070,0x5042,0x5094,
 0x50F4,0x50D8,0x514A,0x5164,0x519D,0x51BE,0x51EC,0x5215,
 0x529C,0x52A6,0x52C0,0x52DB,0x5300,0x5307,0x5324,0x5372,
 0x5393,0x53B2,0x53DD,0xFA0E,0x549C,0x548A,0x54A9,0x54FF,
 0x5586,0x5759,0x5765,0x57AC,0x57C8,0x57C7,0xFA0F,0xFA10,
 0x589E,0x58B2,0x590B,0x5953,0x595B,0x595D,0x5963,0x59A4,
 0x59BA,0x5B56,0x5BC0,0x752F,0x5BD8,0x5BEC,0x5C1E,0x5CA6,
 0x5CBA,0x5CF5,0x5D27,0x5D53,0xFA11,0x5D42,0x5D6D,0x5DB8,
 0x5DB9,0x5DD0,0x5F21,0x5F34,0x5F67,0x5FB7,

 /* ku 90 */
 0x5FDE,0x605D,0x6085,0x608A,0x60DE,0x60D5,0x6120,0x60F2,
 0x6111,0x6137,0x6130,0x6198,0x6213,0x62A6,0x63F5,0x6460,
 0x649D,0x64CE,0x654E,0x6600,0x6615,0x663B,0x6609,0x662E,
 0x661E,0x6624,0x6665,0x6657,0x6659,0xFA12,0x6673,0x6699,
 0x66A0,0x66B2,0x66BF,0x66FA,0x670E,0xF929,0x6766,0x67BB,
 0x6852,0x67C0,0x6801,0x6844,0x68CF,0xFA13,0x6968,0xFA14,
 0x6998,0x69E2,0x6A30,0x6A6B,0x6A46,0x6A73,0x6A7E,0x6AE2,
 0x6AE4,0x6BD6,0x6C3F,0x6C5C,0x6C86,0x6C6F,0x6CDA,0x6D04,
 0x6D87,0x6D6F,0x6D96,0x6DAC,0x6DCF,0x6DF8,0x6DF2,0x6DFC,
 0x6E39,0x6E5C,0x6E27,0x6E3C,0x6EBF,0x6F88,0x6FB5,0x6FF5,
 0x7005,0x7007,0x7028,0x7085,0x70AB,0x710F,0x7104,0x715C,
 0x7146,0x7147,0xFA15,0x71C1,0x71FE,0x72B1,

 /* ku 91 */
 0x72BE,0x7324,0xFA16,0x7377,0x73BD,0x73C9,0x73D6,0x73E3,
 0x73D2,0x7407,0x73F5,0x7426,0x742A,0x7429,0x742E,0x7462,
 0x7489,0x749F,0x7501,0x756F,0x7682,0x769C,0x769E,0x769B,
 0x76A6,0xFA17,0x7746,0x52AF,0x7821,0x784E,0x7864,0x787A,
 0x7930,0xFA18,0xFA19,0xFA1A,0x7994,0xFA1B,0x799B,0x7AD1,
 0x7AE7,0xFA1C,0x7AEB,0x7B9E,0xFA1D,0x7D48,0x7D5C,0x7DB7,
 0x7DA0,0x7DD6,0x7E52,0x7F47,0x7FA1,0xFA1E,0x8301,0x8362,
 0x837F,0x83C7,0x83F6,0x8448,0x84B4,0x8553,0x8559,0x856B,
 0xFA1F,0x85B0,0xFA20,0xFA21,0x8807,0x88F5,0x8A12,0x8A37,
 0x8A79,0x8AA7,0x8ABE,0x8ADF,0xFA22,0x8AF6,0x8B53,0x8B7F,
 0x8CF0,0x8CF4,0x8D12,0x8D76,0xFA23,0x8ECF,0xFA24,0xFA25,
 0x9067,0x90DE,0xFA26,0x9115,0x9127,0x91DA,

 /* ku 92 */
 0x91D7,0x91DE,0x91ED,0x91EE,0x91E4,0x91E5,0x9206,0x9210,
 0x920A,0x923A,0x9240,0x923C,0x924E,0x9259,0x9251,0x9239,
 0x9267,0x92A7,0x9277,0x9278,0x92E7,0x92D7,0x92D9,0x92D0,
 0xFA27,0x92D5,0x92E0,0x92D3,0x9325,0x9321,0x92FB,0xFA28,
 0x931E,0x92FF,0x931D,0x9302,0x9370,0x9357,0x93A4,0x93C6,
 0x93DE,0x93F8,0x9431,0x9445,0x9448,0x9592,0xF9DC,0xFA29,
 0x969D,0x96AF,0x9733,0x973B,0x9743,0x974D,0x974F,0x9751,
 0x9755,0x9857,0x9865,0xFA2A,0xFA2B,0x9927,0xFA2C,0x999E,
 0x9A4E,0x9AD9,0x9ADC,0x9B75,0x9B72,0x9B8F,0x9BB1,0x9BBB,
 0x9C00,0x9D70,0x9D6B,0xFA2D,0x9E19,0x9ED1,0x0000,0x0000,
 0x2170,0x2171,0x2172,0x2173,0x2174,0x2175,0x2176,0x2177,
 0x2178,0x2179,0xFFE2,0xFFE4,0xFF07,0xFF02
};
const int cp932ext2_ucs_table_min = (89 - 1)*94;
const int cp932ext2_ucs_table_max = (89 - 1)*94 + (sizeof (cp932ext2_ucs_table) / sizeof (unsigned short));

const unsigned short cp932ext3_ucs_table[] = {
 /* ku 115 */
 0x2170,0x2171,0x2172,0x2173,0x2174,0x2175,0x2176,0x2177,
 0x2178,0x2179,0x2160,0x2161,0x2162,0x2163,0x2164,0x2165,
 0x2166,0x2167,0x2168,0x2169,0xFFE2,0xFFE4,0xFF07,0xFF02,
 0x3231,0x2116,0x2121,0x2235,0x7E8A,0x891C,0x9348,0x9288,
 0x84DC,0x4FC9,0x70BB,0x6631,0x68C8,0x92F9,0x66FB,0x5F45,
 0x4E28,0x4EE1,0x4EFC,0x4F00,0x4F03,0x4F39,0x4F56,0x4F92,
 0x4F8A,0x4F9A,0x4F94,0x4FCD,0x5040,0x5022,0x4FFF,0x501E,
 0x5046,0x5070,0x5042,0x5094,0x50F4,0x50D8,0x514A,0x5164,
 0x519D,0x51BE,0x51EC,0x5215,0x529C,0x52A6,0x52C0,0x52DB,
 0x5300,0x5307,0x5324,0x5372,0x5393,0x53B2,0x53DD,0xFA0E,
 0x549C,0x548A,0x54A9,0x54FF,0x5586,0x5759,0x5765,0x57AC,
 0x57C8,0x57C7,0xFA0F,0xFA10,0x589E,0x58B2,

 /* ku 116 */
 0x590B,0x5953,0x595B,0x595D,0x5963,0x59A4,0x59BA,0x5B56,
 0x5BC0,0x752F,0x5BD8,0x5BEC,0x5C1E,0x5CA6,0x5CBA,0x5CF5,
 0x5D27,0x5D53,0xFA11,0x5D42,0x5D6D,0x5DB8,0x5DB9,0x5DD0,
 0x5F21,0x5F34,0x5F67,0x5FB7,0x5FDE,0x605D,0x6085,0x608A,
 0x60DE,0x60D5,0x6120,0x60F2,0x6111,0x6137,0x6130,0x6198,
 0x6213,0x62A6,0x63F5,0x6460,0x649D,0x64CE,0x654E,0x6600,
 0x6615,0x663B,0x6609,0x662E,0x661E,0x6624,0x6665,0x6657,
 0x6659,0xFA12,0x6673,0x6699,0x66A0,0x66B2,0x66BF,0x66FA,
 0x670E,0xF929,0x6766,0x67BB,0x6852,0x67C0,0x6801,0x6844,
 0x68CF,0xFA13,0x6968,0xFA14,0x6998,0x69E2,0x6A30,0x6A6B,
 0x6A46,0x6A73,0x6A7E,0x6AE2,0x6AE4,0x6BD6,0x6C3F,0x6C5C,
 0x6C86,0x6C6F,0x6CDA,0x6D04,0x6D87,0x6D6F,

 /* ku 117 */
 0x6D96,0x6DAC,0x6DCF,0x6DF8,0x6DF2,0x6DFC,0x6E39,0x6E5C,
 0x6E27,0x6E3C,0x6EBF,0x6F88,0x6FB5,0x6FF5,0x7005,0x7007,
 0x7028,0x7085,0x70AB,0x710F,0x7104,0x715C,0x7146,0x7147,
 0xFA15,0x71C1,0x71FE,0x72B1,0x72BE,0x7324,0xFA16,0x7377,
 0x73BD,0x73C9,0x73D6,0x73E3,0x73D2,0x7407,0x73F5,0x7426,
 0x742A,0x7429,0x742E,0x7462,0x7489,0x749F,0x7501,0x756F,
 0x7682,0x769C,0x769E,0x769B,0x76A6,0xFA17,0x7746,0x52AF,
 0x7821,0x784E,0x7864,0x787A,0x7930,0xFA18,0xFA19,0xFA1A,
 0x7994,0xFA1B,0x799B,0x7AD1,0x7AE7,0xFA1C,0x7AEB,0x7B9E,
 0xFA1D,0x7D48,0x7D5C,0x7DB7,0x7DA0,0x7DD6,0x7E52,0x7F47,
 0x7FA1,0xFA1E,0x8301,0x8362,0x837F,0x83C7,0x83F6,0x8448,
 0x84B4,0x8553,0x8559,0x856B,0xFA1F,0x85B0,

 /* ku 118 */
 0xFA20,0xFA21,0x8807,0x88F5,0x8A12,0x8A37,0x8A79,0x8AA7,
 0x8ABE,0x8ADF,0xFA22,0x8AF6,0x8B53,0x8B7F,0x8CF0,0x8CF4,
 0x8D12,0x8D76,0xFA23,0x8ECF,0xFA24,0xFA25,0x9067,0x90DE,
 0xFA26,0x9115,0x9127,0x91DA,0x91D7,0x91DE,0x91ED,0x91EE,
 0x91E4,0x91E5,0x9206,0x9210,0x920A,0x923A,0x9240,0x923C,
 0x924E,0x9259,0x9251,0x9239,0x9267,0x92A7,0x9277,0x9278,
 0x92E7,0x92D7,0x92D9,0x92D0,0xFA27,0x92D5,0x92E0,0x92D3,
 0x9325,0x9321,0x92FB,0xFA28,0x931E,0x92FF,0x931D,0x9302,
 0x9370,0x9357,0x93A4,0x93C6,0x93DE,0x93F8,0x9431,0x9445,
 0x9448,0x9592,0xF9DC,0xFA29,0x969D,0x96AF,0x9733,0x973B,
 0x9743,0x974D,0x974F,0x9751,0x9755,0x9857,0x9865,0xFA2A,
 0xFA2B,0x9927,0xFA2C,0x999E,0x9A4E,0x9AD9,

 /* ku 119 */
 0x9ADC,0x9B75,0x9B72,0x9B8F,0x9BB1,0x9BBB,0x9C00,0x9D70,
 0x9D6B,0xFA2D,0x9E19,0x9ED1
};
const int cp932ext3_ucs_table_min = (115 - 1)*94;
const int cp932ext3_ucs_table_max = (115 - 1)*94 + (sizeof (cp932ext3_ucs_table) / sizeof (unsigned short));

#endif /* UNICODE_TABLE_CP932_EXT_H */
