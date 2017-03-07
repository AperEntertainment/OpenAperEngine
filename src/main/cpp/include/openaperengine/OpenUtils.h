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

#ifndef OPENAPERENGINE_OPENUTILS_H
#define OPENAPERENGINE_OPENUTILS_H

#include <stdint.h>
#include <aperutils/utils.h>
#include <glbinding/gl/gl.h>

#ifdef __cplusplus
extern "C" {
#endif // For C++

#define DRAW_TYPE_QUADS GL_QUADS
#define DRAW_TYPE_LINES GL_LINES

#define GL_CLAMP_TO_EDGE 0x812F

#ifdef __cplusplus
}
#endif // For C++


#endif //OPENAPERENGINE_OPENUTILS_H
