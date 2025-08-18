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
            const bn::fixed _bullet_speed = 3; 

            bool _fire = false;
            bn::optional<bn::sprite_ptr> _fire_sprite;
            int _fire_sprite_animation_key = 0;
            const bn::fixed _fire_sprite_animation_max_key = 3;
            bn::fixed _animation_timer = 0;
            const bn::fixed _animation_cooldown = 2;

        public:
            Player();
            void update();

    };
}

#endif