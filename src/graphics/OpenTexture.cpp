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

#include <SOIL/SOIL.h>

#include "../../include/openw67render/graphics/OpenTexture.h"

using namespace std;

/*              OPENGL TEXTURE CALLS                */

void bindTexture(OpenTexture *texture)
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture->id);
}

void unbindTexture()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void deleteTexture(OpenTexture *texture)
{
    glDeleteTextures(1, &texture->id);
}

/*              OPENTEXTUREREGION                */

OpenTextureRegion::OpenTextureRegion(float minX, float minY, float maxX, float maxY) : _minX(minX), _minY(minY),
                                                                                       _maxX(maxX), _maxY(maxY)
{
}

float OpenTextureRegion::minX() const
{
    return _minX;
}

float OpenTextureRegion::minY() const
{
    return _minY;
}

float OpenTextureRegion::maxX() const
{
    return _maxX;
}

float OpenTextureRegion::maxY() const
{
    return _maxY;
}

void OpenTextureRegion::minX(float minX)
{
    _minX = minX;
}

void OpenTextureRegion::minY(float minY)
{
    _minY = minY;
}

void OpenTextureRegion::maxX(float maxX)
{
    _maxX = maxX;
}

void OpenTextureRegion::maxY(float maxY)
{
    _maxY = maxY;
}

const OpenTextureRegion OpenTextureRegion::BASE{0.0, 0.0, 1.0, 1.0};

/* Load and create implementation */

OpenTexture createTexture(unsigned char *image, unsigned int width, unsigned int height, unsigned int channels)
{
    return createTexture(image, width, height, channels, TextureWrapMode::CLAMP, TextureFilterMode::NEAREST);
}

OpenTexture createTexture(unsigned char *image, unsigned int width, unsigned int height, unsigned int channels,
                          TextureWrapMode wrapMode, TextureFilterMode filterMode)
{
    OpenTexture texture = OpenTexture();
    texture.width = width;
    texture.height = height;
    texture.channels = channels;
    texture.id = SOIL_create_OGL_texture(image, width, height, channels, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if (!texture.id)
        throw (string("Failed to load texture").append(LINE_SEPARATOR).append(SOIL_last_result()));

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterMode);

    return texture;
}

OpenTexture loadTexture(string path)
{
    return loadTexture(path, TextureWrapMode::CLAMP, TextureFilterMode::NEAREST);
}

OpenTexture loadTexture(string path, TextureWrapMode wrapMode, TextureFilterMode filterMode)
{
    OpenTexture texture = OpenTexture();
    int width, height;

    texture.id = SOIL_load_OGL_texture(path.c_str(), 4, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);
    if (!texture.id)
        throw (string("Failed to load texture").append(LINE_SEPARATOR).append(SOIL_last_result()));

    texture.width = width;
    texture.height = height;
    texture.channels = 4;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterMode);

    unbindTexture();

    return texture;
}

OpenTextureRegion genTextureRegion(int texWidth, int texHeight, int x, int y, int width, int height)
{
    return OpenTextureRegion((x / texWidth), (y / texHeight), ((x + width) / texWidth), ((y + height) / texHeight));
}