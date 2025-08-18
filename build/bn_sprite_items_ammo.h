#ifndef BN_SPRITE_ITEMS_AMMO_H
#define BN_SPRITE_ITEMS_AMMO_H

#include "bn_sprite_item.h"

//{{BLOCK(ammo_bn_gfx)

//======================================================================
//
//	ammo_bn_gfx, 16x16@8, 
//	+ palette 32 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 64 + 256 = 320
//
//	Time-stamp: 2025-08-18, 13:27:45
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AMMO_BN_GFX_H
#define GRIT_AMMO_BN_GFX_H

#define ammo_bn_gfxTilesLen 256
extern const bn::tile ammo_bn_gfxTiles[8];

#define ammo_bn_gfxPalLen 64
extern const bn::color ammo_bn_gfxPal[32];

#endif // GRIT_AMMO_BN_GFX_H

//}}BLOCK(ammo_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item ammo(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(ammo_bn_gfxTiles, 8), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(ammo_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

