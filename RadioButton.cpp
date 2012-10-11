/* 
 * File:   RadioButton.cpp
 * Author: paulocanedo
 * 
 * Created on 9 de Outubro de 2012, 11:14
 */

#include "RadioButton.h"

#include <iostream>

RadioButton::RadioButton() {
    this->selected = false;
    label = new Label();
    label->setAlign(Component::ComponentAlign::MiddleLeft);
    label->setParent(this);

    this->setText("RadioButton");
    this->paintState = PaintState::Normal;
}

RadioButton::RadioButton(const RadioButton& orig) {
}

RadioButton::~RadioButton() {
}

bool RadioButton::isSelected() {
    return selected;
}

void RadioButton::setSelected(bool selected) {
    this->selected = selected;
}

void RadioButton::setText(string text) {
    label->setText(text);
}

void RadioButton::actionExecuted() {
    setSelected(!isSelected());
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
        graphics->setColor(isStatePressed() ? pcglBootstrapGreen : pcglBootstrapBlue);
        graphics->fillOval(x + gap, cy, radius, radius);
    }
    graphics->setColor(isStateHover() ? pcglBlack : pcglGray);
    graphics->drawOval(x + gap, cy, radius, radius);
    label->render(graphics);
}
