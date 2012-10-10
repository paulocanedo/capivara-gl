/* 
 * File:   Image.h
 * Author: paulocanedo
 *
 * Created on 28 de Setembro de 2012, 10:48
 */
#ifndef IMAGE_H
#define	IMAGE_H

#include <GL/glfw.h>
#include <stdlib.h>
#include <png.h>

class Image {
public:
    Image();
    Image(const Image& orig);
    virtual ~Image();

    int getWidth();
    int getHeight();
    GLubyte* getPixels();
    GLuint getTextureId();
    bool isLoaded();
    
    GLuint loadTexture(const char* filename, int &width, int &height);

    static Image* loadImage(const char* filename);
    static Image* newImage(int width, int height);

    bool hasAlphaChanel();
private:
    int width;
    int height;
    GLubyte* pixels;
    GLuint textureId;
    bool alphaChannel;
};

#endif	/* IMAGE_H */

