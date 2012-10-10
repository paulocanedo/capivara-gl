/* 
 * File:   Panel.cpp
 * Author: paulocanedo
 * 
 * Created on 9 de Outubro de 2012, 14:39
 */

#include <GL/glew.h>
#include <vector>

#include "Panel.h"

Panel::Panel() {
    backgroundColor = pcglCLightGray;
}

Panel::Panel(const Panel& orig) {
}

Panel::~Panel() {
}

void Panel::add(Component* c) {
    components.push_back(c);
    c->setParent(this);
}

void Panel::remove(Component* c) {

}

void Panel::render(Graphics* graphics) {
    paintBackground(graphics);

    for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
        (*it)->render(graphics);
    }

    paintBorder(graphics);
}