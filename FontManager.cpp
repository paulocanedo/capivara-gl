/* 
 * File:   FontManager.cpp
 * Author: paulocanedo
 * 
 * Created on 20 de Setembro de 2012, 16:12
 */

#include "FontManager.h"

FontManager& FontManager::instance() {
    static FontManager fm;
    return fm;
}

FTFont* FontManager::getFont() {
    return this->dfont;
}

FontManager::FontManager() {
    this->dfont = new FTGLTextureFont("/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-R.ttf");
    this->dfont->FaceSize(18);
}

FontManager::FontManager(const FontManager& orig) {
}

FontManager::~FontManager() {
}

