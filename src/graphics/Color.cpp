#include "../../include/openw67render/graphics/Color.h"

namespace Openw67Render
{
    Color::Color(short255 red, short255 green, short255 blue, short255 alpha) : red(red), green(green), blue(blue),
                                                                                alpha(alpha)
    {
    }

    Color::~Color()
    {
        delete &red;
        delete &green;
        delete &blue;
        delete &alpha;
    }

    short255 Color::getRed()
    {
        return red;
    }

    short255 Color::getGreen()
    {
        return green;
    }

    short255 Color::getBlue()
    {
        return blue;
    }

    short255 Color::getAlpha()
    {
        return alpha;
    }

    void Color::ligther()
    {
        short255 i = (short255) (1.0 / (1.0 - 0.7));

        if (red == 0 && green == 0 && blue == 0)
        {
            red = i;
            green = i;
            blue = i;
            return;
        }
        if (red > 0 && red < i)
            red = i;
        if (green > 0 && green < i)
            green = i;
        if (blue > 0 && blue < i)
            blue = i;

        red = max((short255) (red * 0.7), 0);
        green = max((short255) (green * 0.7), 0);
        blue = max((short255) (blue * 0.7), 0);
    }

    void Color::darker()
    {
        red = min((short255) (red / 0.7), 0);
        green = min((short255) (green / 0.7), 0);
        blue = min((short255) (blue / 0.7), 0);
    }

    Color Color::BLACK = Color(0, 0, 0);

    Color Color::WHITE = Color(255, 255, 255);
}