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

#ifndef OPENWAPERENDER_OPENGRAPHICS_H
#define OPENWAPERENDER_OPENGRAPHICS_H

#include "../OpenUtils.h"
#include "OpenTexture.h"
#include "../window/OpenWindow.h"
#include "Color.h"

namespace oar
{
    class OpenGraphics
    {
    private:
        float _complementX = 0.0;
        float _complementY = 0.0;
        bool drawing = false;

    public:
        OpenGraphics(float complementX = 0.0, float complementY = 0.0);

        /*! @brief Gets the complement X of the OpenGraphics.
         *
         * This function returns the complement X of the OpenGraphics.
         * Complement X is used for the coordinates of some drawn objects
         *
         * @return Complement X of the OpenGraphics.
         */
        float complementX() const;

        /*! @brief Gets the complement Y of the OpenGraphics.
         *
         * This function returns the complement Y of the OpenGraphics.
         * Complement Y is used for the coordinates of some drawn objects
         *
         * @return Complement Y of the OpenGraphics.
         */
        float complementY() const;

        void setColor(Color color);

        /*! @brief Enables 2D rendering.
         *
         * This function set OpenGL to render in flat 2D (no perspective) on top of current scene.
         * Preserve current projection and model views, and disable depth testing.
         * Ortho world size will be same as viewport size, so any ortho  will be scaled to fit viewport.
         *
         * @param window Window to get size.
         */
        void setOrthoOn(OpenWindow *window);

        /*! @brief Disables 2D rendering.
         *
         * This function turns 2D mode off.
         * It return the projection and model views to their preserved state was saved when setOrthoOn() was called,
         * and re-enable depth testing.
         *
         */
        void setOrthoOff();

        /*! @brief Enables or disables the transparency.
         *
         * This function enables or disables the OpenGL transparency.
         * It enables the transparency when the parameter transparency is true and it disables the transparency
         * when the paramenter transparency is false.
         *
         * @param transparency True if enable the transparency, else false.
         */
        void setTransparency(bool transparency);

        /*! @brief Gets if the transparency is enabled.
         *
         * This function returns whether the transparency is enabled or disabled.
         *
         * @return True if the transparency is enabled, else false.
         */
        bool isTransparency();

        /*! @brief Enables or disables the use of 2D textures.
         *
         * This function enables or disables the use of 2D textures in OpenGL.
         * If the parameter useTexture2D
         *
         * @param useTexture2D True if enable the use of 2D textures, else false.
         */
        void setTexture2DOn(bool useTexture2D);

        /*! @brief Gets if the use of 2D textures is enabled.
         *
         * This function returns whether the use of 2D texture is enabled or disabled.
         *
         * @return True if the use of 2D textures is enabled, else.
         */
        bool isTexture2D();

        void beginDraw(GLenum drawType);

        void endDraw();

        void vertex2f(float x, float y);

        void vertex3f(float x, float y, float z);

        /*! @brief Draws a line in 2D.
         *
         * This function draws a 2D line.
         *
         * @param x  X position of the first point.
         * @param y  Y position of the first point.
         * @param x2 X position of the second point.
         * @param y2 Y position of the second point.
         */
        void drawLine2D(float x, float y, float x2, float y2);

        /*! @brief Draws an 2D image with a defined texture.
         *
         * This function draws an 2D image with a defined texture.
         *
         * @param texture The defined texture to draw.
         * @param x X position of the image.
         * @param y Y position of the image.
         * @param width Width of the image.
         * @param height Height of the image.
         */
        void drawImage(OpenTexture *texture, float x, float y, float width, float height);

        /*! @brief Draws an 2D image with a defined part texture.
         *
         * This function draws an 2D image with a defined part texture.
         *
         * @param texture The defined texture to draw.
         * @param x X position of the image.
         * @param y Y position of the image.
         * @param width Width of the image.
         * @param height Height of the image.
         * @param region Part of the texture to draw.
         */
        void drawImage(OpenTexture *texture, float x, float y, float width, float height, OpenTextureRegion region);
    };

    /**
     * <p><a href="http://www.opengl.org/sdk/docs/man/html/glViewport.xhtml">OpenGL SDK Reference</a></p>
     * <p>
     * Specifies the viewport transformation parameters for all viewports.
     *
     * @param x      The left viewport coordinate.
     * @param y      The bottom viewport coordinate.
     * @param width  The viewport width.
     * @param height The viewport height.
     */
    void setViewport(int x, int y, int width, int height);
}

#endif //OPENAPERRENDER_OPENGRAPHICS_H
