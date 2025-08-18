#ifndef BN_SPRITE_TILES_ITEMS_FIRE_H
#define BN_SPRITE_TILES_ITEMS_FIRE_H

#include "bn_sprite_tiles_item.h"
#include "bn_sprite_shape_size.h"

//{{BLOCK(fire_bn_gfx)

//======================================================================
//
//	fire_bn_gfx, 16x64@4, 
//	+ 16 tiles not compressed
//	Total size: 512 = 512
//
//	Time-stamp: 2025-08-18, 22:47:20
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FIRE_BN_GFX_H
#define GRIT_FIRE_BN_GFX_H

#define fire_bn_gfxTilesLen 512
extern const bn::tile fire_bn_gfxTiles[16];

#endif // GRIT_FIRE_BN_GFX_H

//}}BLOCK(fire_bn_gfx)

namespace bn::sprite_tiles_items
{
    constexpr inline sprite_tiles_item fire(span<const tile>(fire_bn_gfxTiles, 16), 
            bpp_mode::BPP_4, compression_type::NONE, 4);

    constexpr inline sprite_shape_size fire_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL);
}

#endif

