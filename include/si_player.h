#ifndef SI_PLAYER_H
#define SI_PLAYER_H

#include "si_bullet_buffer.h"

#include "bn_log.h"
#include "bn_span.h"
#include "bn_keypad.h"
#include "bn_optional.h"
#include "bn_fixed_rect.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_items_spaceship.h"
#include "bn_sprite_items_fire.h"


namespace si {
    class Player {
        private:
            // Spaceship attributes
            bn::optional<bn::sprite_ptr> _spaceship_sprite;
            bn::fixed_point _spaceship_position;
            bn::fixed_rect _spaceship_collision;
            bn::fixed _spaceship_speed;

            // Fire animation attributes
            bn::optional<bn::sprite_ptr> _fire_sprite;
            bn::optional<bn::sprite_animate_action<4>> _fire_action;

        public:
            Player(bn::fixed_point spaceship_position, bn::fixed spaceship_speed);
            void update(si::BulletBuffer& player_bullets);
            void hit();

    };
}

#endif
