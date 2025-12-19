#include "si_bullet_buffer.h"

namespace si {
    BulletBuffer::BulletBuffer() {}

    void BulletBuffer::add_buffer(bn::fixed bullet_fire_position_x, bn::fixed bullet_fire_position_y) {
        // If the bullet buffer is full, pop the first element (oldest instatiated bullet)
        if (_bullets.full()){
            _bullets.pop_front();
        }

        // Calculate where the bullet should appear and push the sprite element at the back of the queue
        si::Bullet bullet = si::Bullet(bullet_fire_position_x, bullet_fire_position_y);
        _bullets.push_back(bullet);
    }

    void BulletBuffer::update() {
        for (auto it = _bullets.begin(); it != _bullets.end(); it++) {
            it->get()->update();

            if (!it->get()->has_value()) {
                _bullets.erase(it);
                break;
            }
        }
    }
}
