#include "si_player.h"

#include "bn_log.h"
#include "bn_keypad.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_items_fire.h"

namespace si {
    Player::Player() {}

    void Player::update() {
        // Controller
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

        // Fire a bullet behaviour
        if (bn::keypad::a_pressed()) {
            // If the bullet buffer is full, pop the first element
            if (_bullets.full())
                _bullets.pop_front();

            // Calculate where the bullet should appear and push the sprite element at the back of the queue
            si::Bullet bullet = si::Bullet(_spaceship_sprite.x() - 0.5, _spaceship_sprite.y() - 7.5);
            _bullets.push_back(bullet);

            // Instantiate the player fire sprite and play the animation
            _fire_sprite = bn::sprite_items::fire.create_sprite(_spaceship_sprite.x(), _spaceship_sprite.y() - 2);
            _fire_action = bn::create_sprite_animate_action_once(
                _fire_sprite.value(), 3, bn::sprite_items::fire.tiles_item(), 0, 1, 2, 3);
        }

        for (auto it = _bullets.begin(); it != _bullets.end(); it++) {
            it->get()->update();

            if (it->get()->has_value() == false) {
                _bullets.erase(it);
                break;
            }
        }

        // Fire animation update logic
        if (_fire_action.has_value() && _fire_action.get()->done()) {
            _fire_sprite.reset();
        }

        if (_fire_sprite.has_value()) {
            _fire_action.get()->update();
        } else {
            _fire_action.reset();
        }
    }
}
