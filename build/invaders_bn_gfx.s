
@{{BLOCK(invaders_bn_gfx)

@=======================================================================
@
@	invaders_bn_gfx, 16x32@4, 
@	+ palette 16 entries, not compressed
@	+ 8 tiles not compressed
@	Total size: 32 + 256 = 288
@
@	Time-stamp: 2025-08-18, 10:56:38
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global invaders_bn_gfxTiles		@ 256 unsigned chars
	.hidden invaders_bn_gfxTiles
invaders_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x44400000,0x99940000,0xA3994000,0x33B99400
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000444,0x00004999,0x000499AA,0x00499AA3
	.word 0xBB999400,0x99999400,0x99944000,0x44433400,0x00043340,0x00433400,0x04334000,0x00440000
	.word 0x00499933,0x00499999,0x00044999,0x00433444,0x04334000,0x00433400,0x00043340,0x00004400
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x55000000,0xCC505500,0xCCC5CC50,0xDCCCECC5,0x6ECCCEC5,0xECC5CC50,0xCC505500,0x55000000
	.word 0x00000055,0x005505CC,0x05CC5CCC,0x5CCECCCD,0x5CECCCD6,0x05CC5CCE,0x005505CC,0x00000055

	.section .rodata
	.align	2
	.global invaders_bn_gfxPal		@ 32 unsigned chars
	.hidden invaders_bn_gfxPal
invaders_bn_gfxPal:
	.hword 0x0000,0x20A1,0x28E4,0x352A,0x3DB1,0x2E1A,0x2EBF,0x535F
	.hword 0x6BBF,0x20C6,0x418D,0x28E8,0x1973,0x36DF,0x263B,0x0000

@}}BLOCK(invaders_bn_gfx)
