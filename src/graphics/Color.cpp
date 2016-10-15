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

    Color Color::BLACK = Color(0, 0, 0);

    Color Color::WHITE = Color(255, 255, 255);
}