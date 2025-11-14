#include "si_bullet.h"

namespace si {
    Bullet::Bullet(bn::fixed bullet_fire_position_x, bn::fixed bullet_fire_position_y) {
        _bullet_sprite = bn::sprite_items::ammo.create_sprite(bullet_fire_position_x, bullet_fire_position_y);
        _bullet_sprite.get()->set_scale(0.5);
    }

    bool Bullet::has_value() {
        return _bullet_sprite.has_value();
    }

    void Bullet::update() {
        if (_bullet_sprite.get()->y() >= _screen_limit) {
            _bullet_sprite.get()->set_y(_bullet_sprite.get()->y() + _bullet_speed);
        } else {
            _bullet_sprite.reset();
        }
    }
}
