#include "si_player.h"

#include "bn_log.h"
#include "bn_keypad.h"
#include "bn_sprite_tiles_ptr.h"

#include "bn_sprite_items_ammo.h"
#include "bn_sprite_items_fire.h"

namespace si {
    Player::Player() {}

    void Player::update() {
        if (bn::keypad::left_held() && _spaceship_sprite.x() >= -111) {
            _spaceship_sprite.set_x(_spaceship_sprite.x() - _spaceship_speed);
            _spaceship_sprite.set_tiles(bn::sprite_items::spaceship.tiles_item().create_tiles(1));
        }
        else if (bn::keypad::right_held() && _spaceship_sprite.x() <= 111) {
            _spaceship_sprite.set_x(_spaceship_sprite.x() + _spaceship_speed);
            _spaceship_sprite.set_tiles(bn::sprite_items::spaceship.tiles_item().create_tiles(2));
        }
        else {
            _spaceship_sprite.set_tiles(bn::sprite_items::spaceship.tiles_item().create_tiles(0));
        }
        
        if (bn::keypad::a_pressed()) {
            if (_bullets.full()) {
                _bullets.pop_front();
            } 
            _bullets.push_back(bn::sprite_items::ammo.create_sprite(_spaceship_sprite.x() - 0.5, _spaceship_sprite.y() - 7.5));
            _bullets.back().get()->set_scale(0.5);

            _fire_sprite = bn::sprite_items::fire.create_sprite(_spaceship_sprite.x(), _spaceship_sprite.y() - 2);
            _fire_sprite_animation_key = 1;
        }
        
        for (auto it = _bullets.begin(); it != _bullets.end(); it++) {
            it->get()->set_y(it->get()->y() - _bullet_speed);

            if (it->get()->y() <= -80) {
                _bullets.erase(it);
                break;
            }
        }

        if (_fire_sprite.has_value()) {
            if (_animation_timer == _animation_cooldown) {
                _fire_sprite.get()->set_tiles(bn::sprite_items::fire.tiles_item().create_tiles(_fire_sprite_animation_key));
                if (_fire_sprite_animation_key < _fire_sprite_animation_max_key)
                    _fire_sprite_animation_key+= 1;
                else {
                    _fire_sprite_animation_key = 0;
                    _fire_sprite.reset();
                }
                _animation_timer = 0;
            } else {
                _animation_timer+= 1;
            }
        }
    }
}