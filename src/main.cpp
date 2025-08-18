#include <bn_core.h>
#include <bn_regular_bg_ptr.h>


#include "bn_regular_bg_items_background.h"

int main()
{
    bn::core::init();

    bn::regular_bg_ptr background = bn::regular_bg_items::background.create_bg();

    while(true)
    {
        bn::core::update();
    }
}
