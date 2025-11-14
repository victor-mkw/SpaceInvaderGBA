#ifndef SI_PLAYER_H
#define SI_PLAYER_H

#include "bn_span.h"
#include "bn_deque.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_items_spaceship.h"


namespace si {
    class Player {
        private:
            // Spaceship attributes
            bn::sprite_ptr _spaceship_sprite = bn::sprite_items::spaceship.create_sprite(0, 70);
            bn::fixed_point _spaceship_position = bn::fixed_point(0, 70);
            bn::fixed _spaceship_speed = 1;

            // Bullets attributes
            bn::deque<bn::optional<bn::sprite_ptr>, 32> _bullets;
            const bn::fixed _bullet_speed = -3;

            // Fire animation attributes
            bn::optional<bn::sprite_ptr> _fire_sprite;
            bn::optional<bn::sprite_animate_action<4>> _fire_action;

        public:
            Player();
            void update();

    };
}

#endif
