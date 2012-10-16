/* 
 * File:   Button.cpp
 * Author: paulocanedo
 * 
 * Created on 21 de Setembro de 2012, 17:43
 */

#include "Button.h"
#include "Label.h"

Button::Button() {
    label = new Label();
    label->setAlign(Component::ComponentAlign::MiddleCenter);
    label->setParent(this);

    this->setText("Button");
    this->paintState = PaintState::Normal;
}

Button::Button(const Button& orig) {
}

Button::~Button() {
    delete label;
}

string Button::getComponentName() {
    return "Button";
}

void Button::setAction(Action *action) {
    this->action = action;
}

void Button::actionExecuted() {
    if (action != NULL) {
        action->executed(this);
    }
}

void Button::setText(string text) {
    label->setText(text);

    if (isAutoDimension()) {
        vec2 dim = label->getDimension();
        dim.w += 20;
        dim.h += 6;
        setDimension(dim);
    }
}

//void Button::setImage(Image* image) {
//    label->setImage(image);
//}

string Button::getText() {
    return label->getText();
}

void Button::render(Graphics* graphics) {
    paintBackground(graphics);

    label->setDimension(dimension);
    label->render(graphics);

    paintBorder(graphics);
}

void Button::paintBackground(Graphics* graphics) {
    if (getBackgroundColor().a != 0) {
        vec2 location = getLocation();
        vec2 dimension = getDimension();

        PaintState state = getPaintState();
        if (state == PaintState::Hover) {
            graphics->setColor(pcglBootstrapBlue);
        } else if (state == PaintState::Pressed) {
            graphics->setColor(pcglBootstrapGreen);
        } else {
            graphics->setColor(getBackgroundColor());
        }
        graphics->fillRoundRect(location.x, location.y, dimension.w, dimension.h, dimension.h / 4, dimension.h / 4);
    }
}

void Button::paintBorder(Graphics* graphics) {
    int x = getLocation().x;
    int y = getLocation().y;
    int w = getDimension().w;
    int h = getDimension().h;

    graphics->setColor(getBorderColor());
    graphics->drawRoundRect(x, y, w, h, h / 4, h / 4);
}