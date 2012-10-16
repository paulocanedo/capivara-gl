/* 
 * File:   RadioButton.cpp
 * Author: paulocanedo
 * 
 * Created on 9 de Outubro de 2012, 11:14
 */

#include <vector>

#include "RadioButton.h"

RadioButton::RadioButton() {
    label = new Label();
    label->setAlign(Component::ComponentAlign::MiddleLeft);
    label->setParent(this);
    label->setAutoDimension(true);

    this->selected = false;
    this->dimension.w = 40;
    this->dimension.h = 25;
    this->setText("RadioButton");
    this->paintState = PaintState::Normal;
    setAutoDimension(true);
}

RadioButton::RadioButton(const RadioButton& orig) {
}

RadioButton::~RadioButton() {
}

string RadioButton::getComponentName() {
    return "RadioButton";
}

bool RadioButton::isSelected() {
    return selected;
}

void RadioButton::setSelected(bool selected) {
    this->selected = selected;
}

void RadioButton::setText(string text) {
    label->setText(text);
    
    if(isAutoDimension()) {
        setDimension(getCalculatedDimension());
    }
}

void RadioButton::actionExecuted() {
    setSelected(!isSelected());
}

vec2 RadioButton::getCalculatedDimension() {
    int radius = label->getFont()->LineHeight() * 0.7;
    int gap = radius / 2;

    vec2 dimension;
    dimension.w = label->getDimension().w + radius + gap*3;
    dimension.h = label->getDimension().h + gap;
    return dimension;
}

void RadioButton::render(Graphics* graphics) {
    int x = getLocation().x;
    int y = getLocation().y;

    int w = getDimension().w;
    int h = getDimension().h;

    int radius = label->getFont()->LineHeight() * 0.7;
    int cy = y + (h - radius) / 2;
    int gap = radius / 2;

    paintBackground(graphics);
    
    label->setLocation(radius * 2, 0);
    if (isSelected() || isStatePressed()) {
        graphics->setColor(pcglBootstrapBlue);
        graphics->fillOval(x + gap, cy, radius, radius);

        if (isSelected() && !isStatePressed()) {
            graphics->setColor(0.2, 0.2, 0.2, 0.7);
            int space = radius / 4;
            graphics->fillOval(x + gap + space, cy + space, radius - space * 2, radius - space * 2);
        }
    }
    graphics->setColor(isStateHover() || isSelected() ? pcglBlack : pcglGray);
    graphics->drawOval(x + gap, cy, radius, radius);
    label->render(graphics);
}
