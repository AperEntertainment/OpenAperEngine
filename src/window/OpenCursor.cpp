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

#include <stdexcept>
#include "../../include/openw67render/window/OpenCursor.h"

namespace w67r
{
    OpenCursor::OpenCursor(SDL_Cursor *cursor) : _cursor(cursor)
    {
    }

    SDL_Cursor *OpenCursor::getCursorPointer()
    {
        return _cursor;
    }

    OpenCursor createStandardCursor(SDL_SystemCursor shape)
    {
        SDL_Cursor *cursor = SDL_CreateSystemCursor(shape);
        if (cursor == nullptr)
            throw std::runtime_error("Cannot create the standard cursor with shape: " + std::to_string(shape));
        return OpenCursor(cursor);
    }
}