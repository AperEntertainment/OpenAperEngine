/*
 * Copyright © 2016 Clément "w67clement" Wagner
 *
 * This file is part of Openw67Render.
 *
 * Openw67Render is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Openw67Render is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Openw67Render.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <bits/stl_algobase.h>
#include "../../include/openw67render/graphics/Color.h"

namespace w67r
{
    Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : _red(red), _green(green), _blue(blue),
                                                                            _alpha(alpha)
    {
    }

    uint8_t Color::red() const
    {
        return _red;
    }

    uint8_t Color::green() const
    {
        return _green;
    }

    uint8_t Color::blue() const
    {
        return _blue;
    }

    uint8_t Color::alpha() const
    {
        return _alpha;
    }

    Color Color::ligther()
    {
        uint8_t i = static_cast<uint8_t>(1.0 / (1.0 - 0.7));
        uint8_t lblue = _blue;
        uint8_t lgreen = _green;
        uint8_t lred = _red;

        if (_red == 0 && _green == 0 && _blue == 0)
        {
            return Color(i, i, i, _alpha);
        }
        if (_red > 0 && _red < i)
            lred = i;
        if (_green > 0 && _green < i)
            lgreen = i;
        if (_blue > 0 && _blue < i)
            lblue = i;

        return Color(static_cast<uint8_t>(std::max(static_cast<int> (lred * 0.7), 0)),
                     static_cast<uint8_t>(std::max(static_cast<int> (lgreen * 0.7), 0)),
                     static_cast<uint8_t>(std::max(static_cast<int> (lblue * 0.7), 0)), _alpha);
    }

    Color Color::darker()
    {
        return Color(static_cast<uint8_t>(std::min(static_cast<int>(_red / 0.7), 0)),
                     static_cast<uint8_t>(std::min(static_cast<int>(_green / 0.7), 0)),
                     static_cast<uint8_t>(std::min(static_cast<int>(_blue / 0.7), 0)), _alpha);
    }

    const Color Color::BLACK{0, 0, 0};

    const Color Color::WHITE{255, 255, 255};
}