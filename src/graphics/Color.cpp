#include <bits/stl_algobase.h>
#include "../../include/openw67render/graphics/Color.h"

namespace Openw67Render
{
    Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : _red(red), _green(green), _blue(blue),
                                                                            _alpha(alpha)
    {
    }

    uint8_t Color::red()
    {
        return _red;
    }

    uint8_t Color::green()
    {
        return _green;
    }

    uint8_t Color::blue()
    {
        return _blue;
    }

    uint8_t Color::alpha()
    {
        return _alpha;
    }

    Color Color::ligther()
    {
        uint8_t i = static_cast<uint8_t>(1.0 / (1.0 - 0.7));
        uint8_t __blue = _blue;
        uint8_t __green = _green;
        uint8_t __red = _red;

        if (_red == 0 && _green == 0 && _blue == 0)
        {
            return Color(i, i, i, _alpha);
        }
        if (_red > 0 && _red < i)
            __red = i;
        if (_green > 0 && _green < i)
            __green = i;
        if (_blue > 0 && _blue < i)
            __blue = i;

        return Color(static_cast<uint8_t>(std::max(static_cast<int> (__red * 0.7), 0)),
                     static_cast<uint8_t>(std::max(static_cast<int> (__green * 0.7), 0)),
                     static_cast<uint8_t>(std::max(static_cast<int> (__blue * 0.7), 0)), _alpha);
    }

    Color Color::darker()
    {
        return Color(static_cast<uint8_t>(std::min(static_cast<int>(_red / 0.7), 0)),
                     static_cast<uint8_t>(std::min(static_cast<int>(_green / 0.7), 0)),
                     static_cast<uint8_t>(std::min(static_cast<int>(_blue / 0.7), 0)), _alpha);
    }

    Color Color::BLACK = Color(0, 0, 0);

    Color Color::WHITE = Color(255, 255, 255);
}