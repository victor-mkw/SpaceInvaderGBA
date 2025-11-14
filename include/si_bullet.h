#ifndef SI_BULLET_H
#define SI_BULLET_H

#include "bn_log.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_ammo.h"

namespace si {
    class Bullet{
        private:
            bn::optional<bn::sprite_ptr> _bullet_sprite;
            bn::fixed _bullet_speed = -3;
            bn::fixed _screen_limit = -80;

        public:
            Bullet(bn::fixed bullet_fire_position_x, bn::fixed bullet_fire_position_y);
            bool has_value();
            void update();
    };
}

#endif
