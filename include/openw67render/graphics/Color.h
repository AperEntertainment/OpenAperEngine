#ifndef CPPW67RENDER_COLOR_H
#define CPPW67RENDER_COLOR_H

#include "../OpenUtils.h"

namespace Openw67Render
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

#endif //CPPW67RENDER_COLOR_H
