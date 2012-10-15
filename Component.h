/* 
 * File:   Component.h
 * Author: paulocanedo
 *
 * Created on 30 de Agosto de 2012, 14:17
 */

#ifndef PCGL_COMPONENT_H
#define	PCGL_COMPONENT_H

#include <string>

#include "Graphics.h"
#include "vec234.h"
#include "color.h"

using namespace std;

class Component {
public:
    enum ComponentAlign {
        TopLeft,
        TopCenter,
        TopRight,
        MiddleLeft,
        MiddleCenter,
        MiddleRight,
        BottomLeft,
        BottomCenter,
        BottomRight
    };
    
    enum PaintState {
        Normal,
        Hover,
        Pressed
    };
    
    Component();
    Component(const Component& orig);
    virtual ~Component();
    
    virtual vec2 getLocation();
    virtual void setLocation(vec2 location);
    virtual void setLocation(int x, int y);
    virtual vec2 getDimension();
    virtual void setDimension(vec2 dimension);
    virtual void setDimension(int w, int h);
    virtual vec4 getBackgroundColor();
    virtual void setBackgroundColor(vec4 backgroundColor);
    virtual vec4 getBorderColor();
    virtual void setBorderColor(vec4 color);
    virtual Component* getParent();
    virtual void setParent(Component* component);
    
    bool isStateHover();
    bool isStatePressed();
    bool isStateNormal();
    bool cover(int x, int y);
    
    void mouseEntered();
    void mouseExited();
    virtual void mousePressed(int button, int x, int y);
    virtual void mouseReleased(int button, int x, int y);
    virtual void mouseMoved(int x, int y);
    
    virtual void actionExecuted();
    
    virtual string getComponentName();
    void setAutoDimension(bool autoDimension);
    virtual bool isAutoDimension();
    PaintState getPaintState();
    void setPaintState(PaintState state);
    
    virtual void paintBackground(Graphics* graphics);
    virtual void paintBorder(Graphics* graphics);
    virtual void render(Graphics* graphics);
private:
    bool autoDimension;
protected:
    vec2 location;
    vec2 dimension;
    vec4 backgroundColor;
    vec4 borderColor;
    Component* parent;
    PaintState paintState;
};

#endif	/* COMPONENT_H */

