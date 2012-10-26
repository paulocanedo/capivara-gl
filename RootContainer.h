/* 
 * File:   RootContainer.h
 * Author: paulocanedo
 *
 * Created on 21 de Setembro de 2012, 09:36
 */

#ifndef ROOTCONTAINER_H
#define	ROOTCONTAINER_H

#include <vector>
#include "Panel.h"

using namespace std;

class RootContainer {
public:
    RootContainer();
    RootContainer(const RootContainer& orig);
    virtual ~RootContainer();
    
    void add(Panel* c);
    void remove(Panel* c);
    
    void mousePosition(int x, int y);
    void mouseButton(int button, int state);
    
    void render();
    
    bool isHoverComponent(Component *c, int x, int y);
private:
    Graphics graphics;
    vector<Panel*> container;
    
    vec2 mouseLocation;
};

#endif	/* ROOTCONTAINER_H */

