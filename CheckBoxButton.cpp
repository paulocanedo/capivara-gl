/* 
 * File:   CheckBoxButton.cpp
 * Author: paulocanedo
 * 
 * Created on 17 de Outubro de 2012, 17:19
 */

#include "CheckBoxButton.h"

CheckBoxButton::CheckBoxButton() {
}

CheckBoxButton::CheckBoxButton(const CheckBoxButton& orig) {
}

CheckBoxButton::~CheckBoxButton() {
}

void CheckBoxButton::paintButtonIcon(Graphics *graphics, bool selected, bool pressed, bool hover, int x, int y, int maxDiameter) {
    int diameter = maxDiameter * 0.6;
    int space = diameter * 0.25;
    int gap = space * 2;
    int cy = y + (maxDiameter - diameter) / 2;

    if (selected || pressed) {
        graphics->setColor(pcglBootstrapBlue);
        graphics->fillRect(x + gap, cy, diameter, diameter);

        if (selected && !pressed) {
            graphics->setColor(0.2, 0.2, 0.2, 0.7);
            graphics->fillRect(x + gap + space, cy + space, diameter - space * 2, diameter - space * 2);
        }
    }
    graphics->setColor(hover || selected ? pcglBlack : pcglGray);

    graphics->drawRect(x + gap, cy, diameter, diameter);
}