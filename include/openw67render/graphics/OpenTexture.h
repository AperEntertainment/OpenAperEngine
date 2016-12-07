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

#ifndef OPENW67RENDER_OPENIMAGE_H
#define OPENW67RENDER_OPENIMAGE_H

#include "../OpenUtils.h"
#include <string>

using namespace gl;

enum TextureWrapMode
{
    CLAMP = static_cast<std::underlying_type<GLenum>::type>(GLenum::GL_CLAMP),
    CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
    REPEAT = static_cast<std::underlying_type<GLenum>::type>(GLenum::GL_REPEAT)
};

enum TextureFilterMode
{
    LINEAR = static_cast<std::underlying_type<GLenum>::type>(GLenum::GL_LINEAR),
    NEAREST = static_cast<std::underlying_type<GLenum>::type>(GLenum::GL_NEAREST)
};

typedef enum TextureWrapMode TextureWrapMode;

typedef enum TextureFilterMode TextureFilterMode;

struct OpenTexture
{
    unsigned int id;
    int width;
    int height;
    int channels;
};

/*              OPENGL TEXTURE CALLS                */

void bindTexture(OpenTexture *texture);

void unbindTexture();

void deleteTexture(OpenTexture *texture);

/*              OPENTEXTUREREGION                */

class OpenTextureRegion
{
private:
    /*!
     * Stores the top-left texture X coordinate, with a value between 0.0 and 1.0.
     */
    float _minX;

    /*!
     * Stores the top-left texture Y coordinate, with a value between 0.0 and 1.0.
     */
    float _minY;

    /*!
     * Stores the bottom-right texture X coordinate, with a value between 0.0 and 1.0.
     */
    float _maxX;

    /*!
     * Stores the bottom-right texture Y coordinate, with a value between 0.0 and 1.0.
     */
    float _maxY;

public:
    OpenTextureRegion(float minX, float minY, float maxX, float maxY);

    /*! @brief Gets the top-left corner texture X coordinate.
     *
     * This function returns the top-left corner texture X coordinate.
     *
     * @return X coordinate between 0.0 and 1.0.
     */
    float minX() const;

    /*! @brief Gets the top-left corner texture Y coordinate.
     *
     * This function returns the top-left corner texture Y coordinate.
     *
     * @return Y coordinate between 0.0 and 1.0.
     */
    float minY() const;

    /*! @brief Gets the bottom-right corner texture X coordinate.
     *
     * This function returns the bottom-right corner texture X coordinate.
     *
     * @return X coordinate between 0.0 and 1.0.
     */
    float maxX() const;

    /*! @brief Gets the bottom-right corner texture Y coordinate.
     *
     * This function returns the bottom-right corner texture Y coordinate.
     *
     * @return Y coordinate between 0.0 and 1.0.
     */
    float maxY() const;

    /*! @brief Sets the top-left corner texture X coordinate.
     *
     * This function sets the top-left corner texture X coordinate.
     *
     * @param minX X coordinate between 0.0 and 1.0.
     */
    void minX(float minX);

    /*! @brief Sets the top-left corner texture Y coordinate.
     *
     * This function sets the top-left corner texture Y coordinate.
     *
     * @param minY Y coordinate between 0.0 and 1.0.
     */
    void minY(float minY);

    /*! @brief Sets the bottom-right corner texture X coordinate.
     *
     * This function sets the bottom-right corner texture X coordinate.
     *
     * @param maxX X coordinate between 0.0 and 1.0.
     */
    void maxX(float maxX);

    /*! @brief Sets the bottom-right corner texture Y coordinate.
     *
     * This function sets the bottom-right corner texture Y coordinate.
     *
     * @param maxY Y coordinate between 0.0 and 1.0.
     */
    void maxY(float maxY);

    /*!
     * Represents the whole texture.
     */
    const static OpenTextureRegion BASE;
};

OpenTexture createTexture(unsigned char image[], unsigned int width, unsigned int height, unsigned int channels);

OpenTexture createTexture(unsigned char image[], unsigned int width, unsigned int height, unsigned int channels,
                          TextureWrapMode wrapMode, TextureFilterMode filterMode);

OpenTexture loadTexture(std::string path);

OpenTexture loadTexture(std::string path, TextureWrapMode wrapMode, TextureFilterMode filterMode);

OpenTextureRegion genTextureRegion(int texWidth, int texHeight, int x, int y, int width, int height);

#endif //OPENW67RENDER_OPENIMAGE_H
