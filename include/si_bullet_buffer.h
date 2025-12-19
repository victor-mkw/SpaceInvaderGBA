#ifndef SI_BULLET_BUFFER_H
#define SI_BULLET_BUFFER_H

#include "si_bullet.h"

#include "bn_log.h"
#include "bn_fixed.h"
#include "bn_deque.h"
#include "bn_optional.h"

namespace si {
    class BulletBuffer{
        private:
            bn::deque<bn::optional<si::Bullet>, 32> _bullets;

        public:
            BulletBuffer();
            void add_buffer(bn::fixed bullet_fire_position_x, bn::fixed bullet_fire_position_y);
            void update();
    };
}

#endif
