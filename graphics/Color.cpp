#include "Color.h"

namespace Openw67Render
{

    Color::Color(short255 red, short255 green, short255 blue, short255 alpha)
    {
        Color::red = red;
        Color::green = green;
        Color::blue = blue;
        Color::alpha = alpha;
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
}