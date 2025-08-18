#ifndef SI_PLAYER_H
#define SI_PLAYER_H

#include "bn_deque.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_spaceship.h"


namespace si {
    class Player {
        private:
            bn::sprite_ptr _spaceship_sprite = bn::sprite_items::spaceship.create_sprite(0, 70);
            bn::fixed_point _spaceship_position = bn::fixed_point(0, 70);
            bn::fixed _spaceship_speed = 1;
            bn::deque<bn::optional<bn::sprite_ptr>, 32> _bullets;

        public:
            Player();
            void update();

    };
}

#endif