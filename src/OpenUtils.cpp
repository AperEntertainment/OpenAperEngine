#include "../include/openw67render/OpenUtils.h"

namespace Openw67Render
{
    int min(int x, int y)
    {
        return y ^ ((x ^ y) & -(x < y));
    }

    int max(int x, int y)
    {
        return x ^ ((x ^ y) & -(x < y));
    }

    short255 min(short255 x, short255 y)
    {
        return y ^ ((x ^ y) & -(x < y));
    }

    short255 max(short255 x, short255 y)
    {
        return x ^ ((x ^ y) & -(x < y));
    }
}