/* 
 * File:   RadioButton.cpp
 * Author: paulocanedo
 * 
 * Created on 9 de Outubro de 2012, 11:14
 */

#include "RadioButton.h"

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

void RadioButton::render(Graphics* graphics) {
    int x = getLocation().x;
    int y = getLocation().y;

    int w = getDimension().w;
    int h = getDimension().h;

    int radius = label->getFont()->LineHeight() * 0.7;
    int cy = y + (h - radius) / 2;
    int gap = radius / 2;

    //    paintBackground(graphics);

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

//    int count = (int) round(radius / 10.0);
//    for (int i = 1; i <= count; i++) {
//        graphics->drawOval(x + gap - i, cy - i, radius + i * 2, radius + i * 2);
//    }
//    float oldLineWidth = graphics->getLineWidth();
//    graphics->setLineWidth(max(1.0, radius / 10.0));
    graphics->drawOval(x + gap, cy, radius, radius);
//    graphics->setLineWidth(oldLineWidth);
    label->render(graphics);
}
