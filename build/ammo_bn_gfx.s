
@{{BLOCK(ammo_bn_gfx)

@=======================================================================
@
@	ammo_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2025-08-18, 22:41:41
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global ammo_bn_gfxTiles		@ 128 unsigned chars
	.hidden ammo_bn_gfxTiles
ammo_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x90000000,0x40000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000009,0x00000009
	.word 0x40000000,0x90000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000004,0x00000004,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global ammo_bn_gfxPal		@ 32 unsigned chars
	.hidden ammo_bn_gfxPal
ammo_bn_gfxPal:
	.hword 0x0000,0x1465,0x1067,0x188D,0x1CD8,0x157C,0x123F,0x2AFF
	.hword 0x479D,0x20FC,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(ammo_bn_gfx)
