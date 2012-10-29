/* 
 * File:   Font.cpp
 * Author: paulocanedo
 * 
 * Created on October 29, 2012, 4:08 PM
 */

#include "Font.h"
#include <string>
#include <GL/gl.h>

#ifndef FONT_RENDER_FTGL

Font::Font() {
}

Font::Font(const Font& orig) {
}

Font::~Font() {
}

void Font::setSize(const unsigned int size) {
}

float Font::lineHeight() {
    return 18;
}

float Font::descender() {
    return 2;
}

float Font::ascender() {
    return 2;
}

float Font::advance(const char* text) {
    std::string s = text;
    return 5 * s.length();
}

void Font::render(const char* text, int x, int y) {
    std::string s = text;
    
    float w = 5 * s.length();
    float h = lineHeight();
    
    glEnable(GL_BLEND);
    glColor4f(1.0f, 0.0f, 0.0f, 0.2f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x, y + h);
    glVertex2f(x + w, y + h);
    glVertex2f(x + w, y);
    glEnd();
    glDisable(GL_BLEND);
}

int Font::error() {
    return 0;
}

#else

Font::Font() {
    this->font = new FTGLTextureFont("/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-R.ttf");
}

Font::Font(const Font& orig) {
}

Font::~Font() {
    delete this->font;
}

void Font::setSize(const unsigned int size) {
    this->font->FaceSize(size);
}

float Font::lineHeight() {
    return this->font->LineHeight();
}

float Font::descender() {
    return this->font->Descender();
}

float Font::ascender() {
    return this->font->Ascender();
}

float Font::advance(const char* text) {
    return this->font->Advance(text);
}

void Font::render(const char* text, int x, int y) {
    this->font->Render(text, -1, FTPoint(x, y), FTPoint(), FTGL::RENDER_ALL);
}

int Font::error() {
    return font->Error();
}

#endif