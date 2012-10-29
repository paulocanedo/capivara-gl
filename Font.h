/* 
 * File:   Font.h
 * Author: paulocanedo
 *
 * Created on October 29, 2012, 4:08 PM
 */

#ifndef FONT_H
#define	FONT_H

#include <FTGL/ftgl.h>

class Font {
public:
    Font();
    Font(const Font& orig);
    virtual ~Font();
    
    void setSize(const unsigned int size);
    
    float lineHeight();
    float descender();
    float ascender();
    float advance(const char* text);
    
    void render(const char* text, int x, int y);
    int error();
private:
    FTFont* font;

};

#endif	/* FONT_H */

