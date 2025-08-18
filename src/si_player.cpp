#include "si_player.h"

#include "bn_keypad.h"
#include "bn_sprite_tiles_ptr.h"

#include "bn_sprite_items_ammo.h"

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
            // _bullets.back().get()->set_scale(0.5);
        }
        
        for (auto it = _bullets.begin(); it != _bullets.end(); it++) {
            it->get()->set_y(it->get()->y() - 2);

            if (it->get()->y() <= -80) {
                _bullets.erase(it);
                break;
            }
        }
    }
}