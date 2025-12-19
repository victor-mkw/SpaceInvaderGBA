#ifndef SI_INVADER_H
#define SI_INVADER_H

#include "bn_deque.h"
#include "bn_keypad.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_items_invaders.h"
#include "bn_sprite_items_fire.h"

// namespace si {
//     class Invader {
//         private:
//             bn::optional<bn:sprite_ptr> _invader_sprite;
//             bn::fixed_point _invader_position;
//             bn::fixed _invader_h_speed = 0;
//             bn::fixed _invader_v_speed = 0;
//             bool is_dead = false;

//             // bn::deque<bn::optional<si::Bullet>, 8> _bullets;

//             void _hit();

//         public:
//             Invader(bn::fixed _invader_position_x, bn::fixed _invader_position_y);
//             void update();
//     };
// }

#endif
