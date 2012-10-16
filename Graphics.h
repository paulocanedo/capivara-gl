/* 
 * File:   Graphics.h
 * Author: paulocanedo
 *
 * Created on 30 de Agosto de 2012, 15:27
 */

#ifndef GRAPHICS_H
#define	GRAPHICS_H

#include "vec234.h"
#include "math.h"
#include "pcglPrimitives.h"
#include "color.h"
#include "Image.h"
#include "FontManager.h"

#include <string>
#include <GL/glfw.h>
#include <FTGL/ftgl.h>

using namespace std;

class Graphics {
public:
    Graphics();
    Graphics(const Graphics& orig);
    virtual ~Graphics();

    void drawLine(int x1, int y1, int x2, int y2);
    void drawRect(int x1, int y1, int x2, int y2);
    void drawRoundRect(int x1, int y1, int x2, int y2, int h, int w);
    void drawCircle(int cx, int cy, int r);
    void drawOval(int x1, int y1, int w, int h);
    void drawArc(int cx, int cy, int startAngle, int endAngle);
    void drawString(int x, int y, string text);
    void drawImage(int x, int y, Image* image);

    void fillRect(int x1, int y1, int w, int h);
    void fillCircle(int cx, int cy, int r);
    void fillOval(int x1, int y1, int w, int h);
    void fillRoundRect(int x1, int y1, int w, int h, int ch, int cw);

    void setColor(vec4 color);
    void setColor(float r, float g, float b);
    void setColor(float r, float g, float b, float a);
    vec4 getColor();

    void setLineWidth(float lineWidth);
    float getLineWidth();

    void setFont(FTFont *font);
    FTFont* getFont();
private:
    vec4 color;
    FTFont *font;
    float lineWidth;
};

#endif	/* GRAPHICS_H */

