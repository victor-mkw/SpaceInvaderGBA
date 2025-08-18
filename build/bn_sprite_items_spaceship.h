#ifndef BN_SPRITE_ITEMS_SPACESHIP_H
#define BN_SPRITE_ITEMS_SPACESHIP_H

#include "bn_sprite_item.h"

//{{BLOCK(spaceship_bn_gfx)

//======================================================================
//
//	spaceship_bn_gfx, 16x48@4, 
//	+ palette 16 entries, not compressed
//	+ 12 tiles not compressed
//	Total size: 32 + 384 = 416
//
//	Time-stamp: 2025-08-18, 10:56:38
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SPACESHIP_BN_GFX_H
#define GRIT_SPACESHIP_BN_GFX_H

#define spaceship_bn_gfxTilesLen 384
extern const bn::tile spaceship_bn_gfxTiles[12];

#define spaceship_bn_gfxPalLen 32
extern const bn::color spaceship_bn_gfxPal[16];

#endif // GRIT_SPACESHIP_BN_GFX_H

//}}BLOCK(spaceship_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item spaceship(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(spaceship_bn_gfxTiles, 12), bpp_mode::BPP_4, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(spaceship_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

