/* 
 * File:   FontManager.h
 * Author: paulocanedo
 *
 * Created on 20 de Setembro de 2012, 16:12
 */

#ifndef FONTMANAGER_H
#define	FONTMANAGER_H

#include "Font.h"

class FontManager {
public:
    virtual ~FontManager();
    
    static FontManager& instance();
    Font* getFont();
private:
    FontManager();
    FontManager(const FontManager& orig);
    
    Font font;
};

#endif	/* FONTMANAGER_H */

