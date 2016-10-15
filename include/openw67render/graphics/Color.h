#ifndef CPPW67RENDER_COLOR_H
#define CPPW67RENDER_COLOR_H

#include "../OpenUtils.h"

namespace Openw67Render
{
    class Color
    {
    private:
        short255 red;
        short255 green;
        short255 blue;
        short255 alpha;

    public:
        Color(short255 red, short255 green, short255 blue, short255 alpha = 255);

        ~Color();

        short255 getRed();

        short255 getGreen();

        short255 getBlue();

        short255 getAlpha();

        static Color BLACK;

        static Color WHITE;
    };
}

#endif //CPPW67RENDER_COLOR_H
