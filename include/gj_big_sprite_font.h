/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef GJ_BIG_SPRITE_FONT_H
#define GJ_BIG_SPRITE_FONT_H

#include "bn_sprite_font.h"
#include "bn_utf8_characters_map.h"

#include "bn_sprite_items_big_font.h"
namespace gj {

constexpr bn::utf8_character fixed_32x64_sprite_font_utf8_characters[] = {
    "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ", "á",
    "é", "í", "ó", "ú", "ü", "ñ", "¡", "¿"};

constexpr bn::span<const bn::utf8_character>
    fixed_32x64_sprite_font_utf8_characters_span(
        fixed_32x64_sprite_font_utf8_characters);

constexpr auto fixed_32x64_sprite_font_utf8_characters_map =
    bn::utf8_characters_map<fixed_32x64_sprite_font_utf8_characters_span>();

constexpr bn::sprite_font fixed_32x64_sprite_font(
    bn::sprite_items::big_font,
    fixed_32x64_sprite_font_utf8_characters_map.reference());
} // namespace gj

#endif
