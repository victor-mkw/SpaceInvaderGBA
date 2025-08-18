#ifndef BN_SPRITE_ITEMS_FIRE_H
#define BN_SPRITE_ITEMS_FIRE_H

#include "bn_sprite_item.h"

//{{BLOCK(fire_bn_gfx)

//======================================================================
//
//	fire_bn_gfx, 16x64@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2025-08-18, 22:51:24
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FIRE_BN_GFX_H
#define GRIT_FIRE_BN_GFX_H

#define fire_bn_gfxTilesLen 512
extern const bn::tile fire_bn_gfxTiles[16];

#define fire_bn_gfxPalLen 32
extern const bn::color fire_bn_gfxPal[16];

#endif // GRIT_FIRE_BN_GFX_H

//}}BLOCK(fire_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item fire(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(fire_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(fire_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

