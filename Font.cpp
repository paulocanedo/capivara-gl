/* 
 * File:   Font.cpp
 * Author: paulocanedo
 * 
 * Created on October 29, 2012, 4:08 PM
 */

#include "Font.h"

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