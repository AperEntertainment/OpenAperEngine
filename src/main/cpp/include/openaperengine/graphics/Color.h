/*
 * Copyright © 2016 Clément "w67clement" Wagner
 *
 * This file is part of OpenAperEngine.
 *
 * OpenAperEngine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenAperEngine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 */

#ifndef OPENAPERENGINE_COLOR_H
#define OPENAPERENGINE_COLOR_H

#include "../OpenUtils.h"

namespace oae
{
    class Color
    {
    private:
        uint8_t _red, _green, _blue, _alpha;

    public:
        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

        uint8_t red() const;

        uint8_t green() const;

        uint8_t blue() const;

        uint8_t alpha() const;

        Color ligther();

        Color darker();

        const static Color BLACK;

        const static Color WHITE;
    };
}

#endif //OPENAPERENGINE_COLOR_H
