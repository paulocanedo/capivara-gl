/* 
 * File:   Label.h
 * Author: paulocanedo
 *
 * Created on 29 de Agosto de 2012, 10:43
 */

#ifndef PCGL_LABEL_H
#define	PCGL_LABEL_H

#include <string>
#include "StringTokenizer.hpp"

#include "Image.h"
#include "Component.h"

using namespace std;

class Label : public Component {
private:
    string text;
    vec4 foregroundColor;
    Font *font;
    Image* image;
    ComponentAlign align;
public:
    Label();
    Label(const Label& orig);
    virtual ~Label();
    
    virtual string getComponentName();
    
    int numberOfLines();

    void setFont(Font *font);
    Font* getFont();
    vec4 getForegroundColor();
    void setForegroundColor(vec4 color);
    string getText();
    void setText(string text);
    void setImage(Image* image);
    Image* getImage();
    ComponentAlign getAlign();
    void setAlign(ComponentAlign align);
    void setUnderline(bool underlined);
    
    virtual void render(Graphics* graphics);
protected:
    vec2 getCalculatedDimension();
    bool underlined;
};

#endif	/* LABEL_H */

