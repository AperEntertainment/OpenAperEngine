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

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../OpenUtils.h"
#include <string>

enum TextureWrapMode
{
    CLAMP = GL_CLAMP,
    CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
    REPEAT = GL_REPEAT
};

enum TextureFilterMode
{
    LINEAR = GL_LINEAR,
    NEAREST = GL_NEAREST
};

typedef enum TextureWrapMode TextureWrapMode;

typedef enum TextureFilterMode TextureFilterMode;

class OpenTexture
{
protected:
    const unsigned int _width;
    const unsigned int _height;
    unsigned int _id;

    void init(uint8_t data[]);

private:
    const TextureWrapMode textureWrapMode;
    const TextureFilterMode textureFilterMode;

public:
    OpenTexture(uint8_t data[], unsigned int width, unsigned int height, TextureWrapMode wrapMode,
                TextureFilterMode filterMode);

    ~OpenTexture();

    /*! @brief Gets the ID of the texture.
     *
     * This function returns the generated ID of the texture.
     *
     * @return ID of the texture.
     */
    unsigned int id() const;

    /*! @brief Gets the width of the texture.
     *
     * This function returns the width of the texture.
     *
     * @return Width of the texture.
     */
    unsigned int width() const;

    /*! @brief Gets the height of the texture.
     *
     * This function returns the height of the texture.
     *
     * @return Height of the texture.
     */
    unsigned int height() const;

    /*! @brief Gets the wrap mode of the texture.
     *
     * This function returns the wrap mode of the texture.
     *
     * @return Wrap mode of the texture.
     */
    TextureWrapMode getWrapMode() const;

    /*! @brief Gets the filter mode of the texture.
     *
     * This function returns the filter mode of the texture.
     *
     * @return Filter mode of the texture.
     */
    TextureFilterMode getFilterMode() const;

    /*! @brief Binds the texture.
     *
     * This function binds the texture for an OpenGL use.
     */
    void bind();

    /*! @brief Unbinds the texture.
     *
     * This function unbinds the texture for an OpenGL use.
     */
    void unbind();

    /*! @brief Deletes the texture.
     *
     * This function deletes the texture with OpenGL.
     */
    void deleteTexture();
};

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

OpenTexture createTexture(uint8_t image[], unsigned int width, unsigned int height);

OpenTexture createTexture(uint8_t image[], unsigned int width, unsigned int height, TextureWrapMode wrapMode,
                          TextureFilterMode filterMode);

OpenTexture loadTexture(std::string path);

OpenTexture loadTexture(std::string path, TextureWrapMode wrapMode, TextureFilterMode filterMode);

OpenTextureRegion genTextureRegion(int texWidth, int texHeight, int x, int y, int width, int height);

#endif //OPENW67RENDER_OPENIMAGE_H
