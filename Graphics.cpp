/* 
 * File:   Graphics.cpp
 * Author: paulocanedo
 * 
 * Created on 30 de Agosto de 2012, 15:27
 */

#include "Graphics.h"

using namespace std;

Graphics::Graphics() {
    this->color = pcglBlack;

    this->font = FontManager::instance().getFont();
    this->lineWidth = 1.0f;
    
    this->offset.x = 0;
    this->offset.y = 0;
}

Graphics::Graphics(const Graphics& orig) {
}

Graphics::~Graphics() {
    if (this->font != NULL) delete (this->font);
}

void Graphics::setColor(vec4 color) {
    glColor4f(color.r, color.g, color.b, color.a);
    this->color = color;
}

void Graphics::setColor(float r, float g, float b) {
    glColor4f(r, g, b, 1.0);
    this->color.r = r;
    this->color.g = g;
    this->color.b = b;
    this->color.a = 1.0;
}

void Graphics::setColor(float r, float g, float b, float a) {
    glColor4f(r, g, b, a);
    this->color.r = r;
    this->color.g = g;
    this->color.b = b;
    this->color.a = 1.0;
}

void Graphics::drawString(int x, int y, string text) {
    int wWidth, wHeight;
    glfwGetWindowSize(&wWidth, &wHeight);

    y = wHeight - y - font->LineHeight();
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, wWidth, 0, wHeight, -1, 1);

    if (!font->Error()) {
        font->Render(text.c_str(), -1, FTPoint(x + this->offset.x, y - this->offset.y, 0), FTPoint(), FTGL::RENDER_ALL);
    } else {
        throw 0;
    }
    glPopMatrix();
}

void Graphics::drawRoundRect(int x1, int y1, int w, int h, int ch, int cw) {
    pcglDrawRoundRect(x1, y1, x1 + w, y1 + h, cw, ch, false);
}

void Graphics::drawImage(int x, int y, Image* image) {
    int w = image->getWidth();
    int h = image->getHeight();

    //    glColor4f(1, 1, 1, 1);
    //    glBindTexture(GL_TEXTURE_2D, image->getTextureId());
    //    
    //    glEnable(GL_TEXTURE_2D);
    //    glBegin(GL_QUADS);
    //    glTexCoord2f(0.0, 0.0);
    //    glVertex3f(w + x, h + y, 0);
    //
    //    glTexCoord2f(1.0, 0.0);
    //    glVertex3f(w + x - w, h + y, 0.0);
    //
    //    glTexCoord2f(1.0, 1.0);
    //    glVertex3f(w + x - w, h + y - h, 0.0);
    //
    //    glTexCoord2f(0.0, 1.0);
    //    glVertex3f(w + x, h + y - h, 0);
    //    glEnd();
    //
    //    glBindTexture(GL_TEXTURE_2D, 0);
    //    glDisable(GL_TEXTURE_2D);

    glRasterPos2d(x, y + h);
    glDrawPixels(w, h, image->hasAlphaChanel() ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image->getPixels());
}

void Graphics::fillRoundRect(int x1, int y1, int w, int h, int ch, int cw) {
    pcglDrawRoundRect(x1, y1, x1 + w, y1 + h, cw, ch, true);
}

void Graphics::fillRect(int x1, int y1, int w, int h) {
    pcglFillRect(x1, y1, x1 + w, y1 + h);
}

void Graphics::drawRect(int x1, int y1, int w, int h) {
    pcglDrawRect(x1, y1, x1 + w, y1 + h);
}

void Graphics::drawCircle(int cx, int cy, int r) {
    pcglDrawArc(cx, cy, 0, 360, r, r);
}

void Graphics::drawOval(int x1, int y1, int w, int h) {
    pcglDrawArc(x1 + w/2, y1 + h/2, 0, 360, w/2, h/2);
}

void Graphics::fillOval(int x1, int y1, int w, int h) {
    pcglFillArc(x1 + w/2, y1 + h/2, 0, 360, w/2, h/2);
}

void Graphics::setLineWidth(float lineWidth) {
    glLineWidth(lineWidth);
    this->lineWidth = lineWidth;
}

float Graphics::getLineWidth() {
    return this->lineWidth;
}

void Graphics::setFont(FTFont *font) {
    this->font = font;
}

FTFont* Graphics::getFont() {
    return this->font;
}

void Graphics::setOffset(int x, int y) {
    glTranslatef(-(this->offset.x), -(this->offset.y), 0); //restore offset 0,0
    
    this->offset.x = x;
    this->offset.y = y;
    
    glTranslatef(this->offset.x, this->offset.y, 0); //make offset x, y
}