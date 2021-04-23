#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_ptr.h"
#include "bn_keypad.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_animate_actions.h"
#include "bn_regular_bg_ptr.h"
#include "bn_vector.h"

#include "gj_big_sprite_font.h"
#include "bn_sprite_items_ninja.h"
#include "bn_sprite_items_pipe.h"
#include "bn_regular_bg_items_bg_day.h"

int main()
{
    bn::core::init();

    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    bn::regular_bg_ptr day_bg = bn::regular_bg_items::bg_day.create_bg(0, 0);
    day_bg.set_visible(true);

    bn::sprite_text_generator text_generator(gj::big_sprite_font);

    text_generator.set_center_alignment();
    bn::vector<bn::sprite_ptr, 32> text_sprites;

    text_generator.generate(0, -20, "Bzioup", text_sprites);

    bn::sprite_ptr ninja_sprite = bn::sprite_items::ninja.create_sprite(0, 0);
    bn::sprite_animate_action<4> action = bn::create_sprite_animate_action_forever(
                    ninja_sprite, 16, bn::sprite_items::ninja.tiles_item(), 12, 13, 14, 15);

    bn::sprite_ptr pipe_sprite = bn::sprite_items::pipe.create_sprite(10, 10);
    pipe_sprite.set_scale(2);

    while(true)
    {

        if (bn::keypad::right_held())
        {
            ninja_sprite.set_x(ninja_sprite.x() + 1);
        }

        if (bn::keypad::left_held())
        {
            ninja_sprite.set_x(ninja_sprite.x() - 1);
        }

        day_bg.set_x(day_bg.x() - 1);

        bn::core::update();
        action.update();
    }
}
