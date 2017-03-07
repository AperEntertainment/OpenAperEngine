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
 * along with OpenAperEngine.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OPENAPERENGINE_OPENCURSOR_H
#define OPENAPERENGINE_OPENCURSOR_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace oae
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
#endif //OPENAPERENGINE_OPENCURSOR_H
