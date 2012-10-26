/* 
 * File:   RadioButton.cpp
 * Author: paulocanedo
 * 
 * Created on 9 de Outubro de 2012, 11:14
 */

#include "RadioButton.h"

#include <iostream>

vector<RadioButton*> RadioButton::buttons;

RadioButton::RadioButton() {
    label = new Label();
    label->setAlign(Component::ComponentAlign::MiddleLeft);
    label->setParent(this);

    this->selected = false;
    this->setText("RadioButton");
    this->paintState = PaintState::Normal;
    this->groupId = 0;

    buttons.push_back(this);
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

RadioButton* RadioButton::querySelectedRadioButton() {
    return querySelectedRadioButton(this->groupId);
}

RadioButton* RadioButton::querySelectedRadioButton(int groupId) {
    for (vector<RadioButton*>::iterator it = buttons.begin(); it != buttons.end(); ++it) {
        if (groupId == (*it)->groupId && (*it)->selected)
            return (*it);
    }
    return NULL;
}

void RadioButton::clearGroupSelection() {
    clearGroupSelection(this->groupId);
}

void RadioButton::clearGroupSelection(int groupId) {
    for (vector<RadioButton*>::iterator it = buttons.begin(); it != buttons.end(); ++it) {
        if (groupId == (*it)->groupId)
            (*it)->selected = false;
    }
}

void RadioButton::setSelected(bool selected) {
    if (this->groupId > 0) {
        clearGroupSelection(this->groupId);
    }
    this->selected = selected;
}

string RadioButton::getText() {
    return label->getText();
}

void RadioButton::setText(string text) {
    label->setText(text);
    int radius = label->getFont()->LineHeight() * 0.7;

    label->setLocation(radius * 2, 0);

    if (isAutoDimension()) {
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
    dimension.w = label->getDimension().w + radius + gap * 3;
    dimension.h = label->getDimension().h + gap;
    return dimension;
}

void RadioButton::paintButtonIcon(Graphics *graphics, bool selected, bool pressed, bool hover, int x, int y, int maxDiameter) {
    int diameter = maxDiameter * 0.6;
    int space = diameter * 0.25;
    int gap = space * 2;
    int cy = y + (maxDiameter - diameter) / 2;

    if (selected || pressed) {
        graphics->setColor(pcglBootstrapBlue);
        graphics->fillOval(x + gap, cy, diameter, diameter);

        if (selected && !pressed) {
            graphics->setColor(0.2, 0.2, 0.2, 0.7);
            graphics->fillOval(x + gap + space, cy + space, diameter - space * 2, diameter - space * 2);
        }
    }
    graphics->setColor(hover || selected ? pcglBlack : pcglGray);

    graphics->drawOval(x + gap, cy, diameter, diameter);
}

void RadioButton::render(Graphics* graphics) {
    int x = getLocation().x;
    int y = getLocation().y;

    int w = getDimension().w;
    int h = getDimension().h;

//    paintBackground(graphics);

    paintButtonIcon(graphics, isSelected(), isStatePressed(), isStateHover(), x, y, min(w, h));
    label->render(graphics);
}
