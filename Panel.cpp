/* 
 * File:   Panel.cpp
 * Author: paulocanedo
 * 
 * Created on 9 de Outubro de 2012, 14:39
 */

#include "Panel.h"
#include <iostream>

Panel::Panel() {
    backgroundColor = pcglCLightGray;
}

Panel::Panel(const Panel& orig) {
}

Panel::~Panel() {
}

string Panel::getComponentName() {
    return "Panel";
}

void Panel::add(Component* c) {
    components.push_back(c);
    c->setParent(this);
}

void Panel::remove(Component* c) {

}

void Panel::mouseMoved(int x, int y) {
    for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
        if ((*it)->cover(x, y)) {
            if (!(*it)->isStateHover() && !(*it)->isStatePressed())
                (*it)->mouseEntered();
        } else {
            if ((*it)->isStateHover())
                (*it)->mouseExited();
        }

        (*it)->mouseMoved(x, y);
    }
}

void Panel::mousePressed(int button, int x, int y) {
    for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
        if ((*it)->cover(x, y)) {
            (*it)->mousePressed(button, x, y);
        }
    }
}

void Panel::mouseReleased(int button, int x, int y) {
    for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
        if ((*it)->cover(x, y)) {
            (*it)->mouseReleased(button, x, y);
        } else {
            (*it)->setPaintState(Component::PaintState::Normal);
        }
    }
}

void Panel::render(Graphics* graphics) {
    paintBackground(graphics);

    for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
        (*it)->render(graphics);
    }

    paintBorder(graphics);
}