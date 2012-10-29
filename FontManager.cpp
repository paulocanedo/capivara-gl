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

Font* FontManager::getFont() {
    return &font;
}

FontManager::FontManager() {
//    font = new Font();
    font.setSize(16);
}

FontManager::FontManager(const FontManager& orig) {
//    delete font;
}

FontManager::~FontManager() {
}

