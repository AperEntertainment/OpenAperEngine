/*
 * Copyright © 2016 Clément "w67clement" Wagner
 *
 * This file is part of OpenAperRender.
 *
 * OpenAperRender is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenAperRender is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with OpenAperRender.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OPENAPERRENDER_OPENCURSOR_H
#define OPENAPERRENDER_OPENCURSOR_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace oar
{
    class OpenCursor
    {
    private:
        GLFWcursor *cursor;

    public:
        OpenCursor(GLFWcursor *cursor);

        GLFWcursor *getCursorPointer();
    };

    OpenCursor createStandardCursor(unsigned int shape);
}
#endif //OPENAPERRENDER_OPENCURSOR_H
