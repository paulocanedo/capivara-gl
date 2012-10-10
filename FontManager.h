/* 
 * File:   FontManager.h
 * Author: paulocanedo
 *
 * Created on 20 de Setembro de 2012, 16:12
 */

#ifndef FONTMANAGER_H
#define	FONTMANAGER_H

#include <FTGL/ftgl.h>

class FontManager {
public:
    virtual ~FontManager();
    
    static FontManager& instance();
    FTFont* getFont();
private:
    FontManager();
    FontManager(const FontManager& orig);
    
    FTFont* dfont;
};

#endif	/* FONTMANAGER_H */

