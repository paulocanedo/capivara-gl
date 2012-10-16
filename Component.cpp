/* 
 * File:   Component.cpp
 * Author: paulocanedo
 * 
 * Created on 30 de Agosto de 2012, 14:17
 */

#include "Component.h"

Component::Component() {
    location = {
        {0, 0}
    };
    dimension = {
        {10, 10}
    };
    backgroundColor = pcglLightGray;
    borderColor = pcglBlack;

    autoDimension = true;
}

Component::Component(const Component& orig) {
}

Component::~Component() {
}

Component* Component::getParent() {
    return parent;
}

void Component::setParent(Component* component) {
    this->parent = component;
}

vec2 Component::getLocation() {
    return this->location;
}

void Component::setLocation(vec2 location) {
    this->location = location;
}

void Component::setLocation(int x, int y) {
    this->location.x = x;
    this->location.y = y;
}

vec2 Component::getDimension() {
    return this->dimension;
}

void Component::setDimension(vec2 dimension) {
    this->setDimension(dimension.w, dimension.h);
}

void Component::setDimension(int w, int h) {
    this->dimension.w = w;
    this->dimension.h = h;
}

vec4 Component::getBackgroundColor() {
    return this->backgroundColor;
}

void Component::setBackgroundColor(vec4 backgroundColor) {
    this->backgroundColor = backgroundColor;
}

vec4 Component::getBorderColor() {
    return borderColor;
}

void Component::setBorderColor(vec4 color) {
    this->borderColor = color;
}

string Component::getComponentName() {
    return "Component";
}

void Component::setAutoDimension(bool autoDimension) {
    this->autoDimension = autoDimension;
}

bool Component::isAutoDimension() {
    return this->autoDimension;
}

Component::PaintState Component::getPaintState() {
    return this->paintState;
}

void Component::setPaintState(PaintState state) {
    this->paintState = state;
}

void Component::paintBackground(Graphics* graphics) {
    if (getBackgroundColor().a != 0) {
        vec2 location = getLocation();
        vec2 dimension = getDimension();
        graphics->setColor(getBackgroundColor());
        graphics->fillRect(location.x, location.y, dimension.w, dimension.h);
    }
}

void Component::paintBorder(Graphics* graphics) {

}

void Component::render(Graphics* graphics) {

}

bool Component::isStateHover() {
    return paintState == Hover;
}

bool Component::isStatePressed() {
    return paintState == Pressed;
}

bool Component::isStateNormal() {
    return paintState == Normal;
}

bool Component::cover(int x, int y) {
    vec2 location = getLocation();
    vec2 dimension = getDimension();

    return ((x > location.x && x < (location.x + dimension.w)) &&
            (y > location.y && y < (location.y + dimension.y)));
}

void Component::mouseEntered() {
    if (!isStatePressed())
        paintState = PaintState::Hover;
}

void Component::mouseExited() {
    if (!isStatePressed())
        paintState = PaintState::Normal;
}

void Component::mouseMoved(int x, int y) {

}

void Component::mousePressed(int button, int x, int y) {
    if (button == 0) {
        paintState = PaintState::Pressed;
    }
}

void Component::mouseReleased(int button, int x, int y) {
    if (button == 0) {
        actionExecuted();
        paintState = PaintState::Hover;
    }
}

void Component::actionExecuted() {
    
}