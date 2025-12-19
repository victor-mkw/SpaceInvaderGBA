#include "si_player.h"
#include "si_bullet_buffer.h"

#include "bn_core.h"
#include "bn_fixed_point.h"
#include "bn_regular_bg_ptr.h"

#include "bn_regular_bg_items_background.h"

int main()
{
    bn::core::init();

    bn::regular_bg_ptr background = bn::regular_bg_items::background.create_bg();

    si::BulletBuffer player_bullets = si::BulletBuffer();
    si::Player player = si::Player(bn::fixed_point(0, 70), 1);

    while(true)
    {
        player.update(player_bullets);
        player_bullets.update();
        bn::core::update();
    }
}
