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

#define STB_IMAGE_IMPLEMENTATION

#include "../../include/stb/stb_image.h"

#include "../../include/openw67render/graphics/OpenTexture.h"

/* OpenTexture implementation */

OpenTexture::OpenTexture(uint8_t data[], unsigned int width, unsigned int height, TextureWrapMode wrapMode,
                         TextureFilterMode filterMode) : _width(width), _height(height), textureWrapMode(wrapMode),
                                                         textureFilterMode(filterMode)
{
    init(data);
}

void OpenTexture::init(uint8_t data[])
{
    GLuint tempId;
    glGenTextures(1, &tempId);
    _id = tempId;

    glBindTexture(GL_TEXTURE_2D, _id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureWrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureFilterMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, textureFilterMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, textureFilterMode);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
}

void OpenTexture::deleteTexture()
{
    const GLuint tempId(_id);
    glDeleteTextures(1, &tempId);
}

unsigned int OpenTexture::id() const
{
    return _id;
}

unsigned int OpenTexture::width() const
{
    return _width;
}

unsigned int OpenTexture::height() const
{
    return _height;
}

TextureWrapMode OpenTexture::getWrapMode() const
{
    return textureWrapMode;
}

TextureFilterMode OpenTexture::getFilterMode() const
{
    return textureFilterMode;
}

void OpenTexture::bind()
{
    glActiveTexture(_id);
    glBindTexture(GL_TEXTURE_2D, _id);
}

void OpenTexture::unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

OpenTexture::~OpenTexture()
{
    if (_id != 0)
        deleteTexture();
}

/* OpenTextureRegion implementation */

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
    return _minY;
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

OpenTexture createTexture(uint8_t image[], unsigned int width, unsigned int height)
{
    return createTexture(image, width, height, TextureWrapMode::CLAMP, TextureFilterMode::NEAREST);
}

OpenTexture createTexture(uint8_t image[], unsigned int width, unsigned int height, TextureWrapMode wrapMode,
                          TextureFilterMode filterMode)
{
    return OpenTexture(image, width, height, wrapMode, filterMode);
}

OpenTexture loadTexture(std::string path)
{
    return loadTexture(path, TextureWrapMode::CLAMP, TextureFilterMode::NEAREST);
}

OpenTexture loadTexture(std::string path, TextureWrapMode wrapMode, TextureFilterMode filterMode)
{
    int width;
    int height;
    int comp;
    // Load image
    stbi_set_flip_vertically_on_load(1);
    uint8_t *data = stbi_load(path.c_str(), &width, &height, &comp, STBI_rgb_alpha);
    if (data == nullptr)
        throw (std::string("Failed to load texture").append(LINE_SEPARATOR).append(stbi_failure_reason()));

    OpenTexture texture = createTexture(data, static_cast<unsigned int>(width), static_cast<unsigned int>(height),
                                        wrapMode, filterMode);
    stbi_image_free(data);
    return texture;
}

OpenTextureRegion genTextureRegion(int texWidth, int texHeight, int x, int y, int width, int height)
{
    return OpenTextureRegion((x / texWidth), (y / texHeight), ((x + width) / texWidth), ((y + height) / texHeight));
}