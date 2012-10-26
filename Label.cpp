/* 
 * File:   Label.cpp
 * Author: paulocanedo
 * 
 * Created on 29 de Agosto de 2012, 10:43
 */

#include "Label.h"

Label::Label() {
    this->foregroundColor = pcglDarkGray;
    this->location = {
        {0, 0}
    };
    this->align = TopLeft;
    this->text = "";
    this->font = FontManager::instance().getFont();
    this->parent = NULL;
    this->backgroundColor.a = 0;
    this->image = NULL;
    setAutoDimension(true);
}

Label::Label(const Label& orig) {
}

Label::~Label() {
}

string Label::getComponentName() {
    return "Label";
}

int Label::numberOfLines() {
    StringTokenizer* st = new StringTokenizer(this->getText());

    int i = 0;
    while (!st->isFinished()) {
        i++;
        st->nextElement('\n');
    }

    delete st;
    return i;
}

void Label::setFont(FTFont *font) {
    this->font = font;
}

FTFont* Label::getFont() {
    return this->font;
}

string Label::getText() {
    return text;
}

void Label::setText(string text) {
    this->text = text;

    if (isAutoDimension()) {
        setDimension(getCalculatedDimension());
    }
}

void Label::setImage(Image* image) {
    this->image = image;
}

Image* Label::getImage() {
    return this->image;
}

Component::ComponentAlign Label::getAlign() {
    return align;
}

void Label::setAlign(Component::ComponentAlign align) {
    this->align = align;
}

vec4 Label::getForegroundColor() {
    return foregroundColor;
}

void Label::setForegroundColor(vec4 color) {
    this->foregroundColor = color;
}

vec2 Label::getCalculatedDimension() {
    int nLines = numberOfLines();
    float height = font->LineHeight() * nLines;

    float width = 0;
    StringTokenizer* st = new StringTokenizer(this->getText());
    while (!st->isFinished()) {
        string s = st->nextElement('\n');

        float w = font->Advance(s.c_str());
        width = max(width, w);
        if (image) {
            width = max((int) width, image->getWidth());
            height = max((int) height, image->getHeight());
        }
    }
    delete st;

    return
    {
        {
            width, height
        }
    };
}

void Label::render(Graphics* graphics) {
    paintBackground(graphics);
    
    float hs = graphics->getFont()->LineHeight();
    int nLines = numberOfLines();

    vec2 location = getLocation();
    vec2 dimension = getDimension();

    int x = location.x;
    int y = location.y;
    int w = dimension.w;
    int h = dimension.h;
    
    int dx, dy = 0;
    if(parent != NULL) {
        dx = parent->getLocation().x;
        dy = parent->getLocation().y;
    }
    x += dx;
    y += dy;

    StringTokenizer* st = new StringTokenizer(this->getText());
    int currentLine = 0;
    while (!st->isFinished()) {
        currentLine++;
        string s = st->nextElement('\n');
        float ws = font->Advance(s.c_str());

        int px = 0, py = 0;
        if (align == Component::ComponentAlign::TopCenter ||
                align == Component::ComponentAlign::MiddleCenter ||
                align == Component::ComponentAlign::BottomCenter) {
            px = (w - ws) / 2;
        }
        if (align == Component::ComponentAlign::TopRight ||
                align == Component::ComponentAlign::MiddleRight ||
                align == Component::ComponentAlign::BottomRight) {
            px = w - ws;
        }
        if (align == Component::ComponentAlign::MiddleLeft ||
                align == Component::ComponentAlign::MiddleCenter ||
                align == Component::ComponentAlign::MiddleRight) {
            py = (h + nLines * hs) / 2 - (hs * (nLines - currentLine + 1));
        }
        if (align == Component::ComponentAlign::BottomLeft ||
                align == Component::ComponentAlign::BottomCenter ||
                align == Component::ComponentAlign::BottomRight) {
            py = h - (hs * (nLines - currentLine + 1));
        }
        if (align == Component::ComponentAlign::TopLeft ||
                align == Component::ComponentAlign::TopCenter ||
                align == Component::ComponentAlign::TopRight) {
            py += hs * (currentLine - 1);
        }

        if (image)
            graphics->drawImage(x, y, image);

        graphics->setColor(this->foregroundColor);
        graphics->drawString(x + px, y + py, s);
    }
    delete st;
}