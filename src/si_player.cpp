#include "si_player.h"

namespace si {
    Player::Player(bn::fixed_point spaceship_position, bn::fixed spaceship_speed) {
        _spaceship_position = spaceship_position;
        _spaceship_sprite = bn::sprite_items::spaceship.create_sprite(_spaceship_position);
        _spaceship_collision = bn::fixed_rect(_spaceship_position, _spaceship_sprite.get()->dimensions());
        _spaceship_speed = spaceship_speed;
    }

    void Player::update(si::BulletBuffer& player_bullets) {
        // Controller
        if (bn::keypad::left_held() && _spaceship_position.x() >= -111) {
            _spaceship_position.set_x(_spaceship_position.x() - _spaceship_speed);
            _spaceship_sprite.get()->set_tiles(bn::sprite_items::spaceship.tiles_item().create_tiles(1));
        }
        else if (bn::keypad::right_held() && _spaceship_position.x() <= 111) {
            _spaceship_position.set_x(_spaceship_position.x() + _spaceship_speed);
            _spaceship_sprite.get()->set_tiles(bn::sprite_items::spaceship.tiles_item().create_tiles(2));
        }
        else {
            _spaceship_sprite.get()->set_tiles(bn::sprite_items::spaceship.tiles_item().create_tiles(0));
        }

        // Fire a bullet behaviour
        if (bn::keypad::a_pressed()) {
            player_bullets.add_buffer(_spaceship_position.x() - 0.5, _spaceship_position.y() - 7.5);

            // Instantiate the player fire sprite and play the animation
            _fire_sprite = bn::sprite_items::fire.create_sprite(_spaceship_position.x(), _spaceship_position.y() - 2);
            _fire_action = bn::create_sprite_animate_action_once(
                _fire_sprite.value(), 3, bn::sprite_items::fire.tiles_item(), 0, 1, 2, 3);
        }

        // Fire animation update logic (TODO : simplify animation business)
        if (_fire_action.has_value() && _fire_action.get()->done()) {
            _fire_sprite.reset();
        }

        if (_fire_sprite.has_value()) {
            _fire_action.get()->update();
        } else {
            _fire_action.reset();
        }

        _spaceship_sprite.get()->set_position(_spaceship_position);
        _spaceship_collision.set_position(_spaceship_position);
    }

    void hit() {

    }
}
