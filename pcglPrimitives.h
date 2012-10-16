/* 
 * File:   pcglPrimitives.h
 * Author: paulocanedo
 *
 * Created on 20 de Setembro de 2012, 13:44
 */

#ifndef PCGLPRIMITIVES_H
#define	PCGLPRIMITIVES_H

#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>

#define DEGREES_TO_RADIANS(x) (3.14159265358979323846 * x / 180.0)

#ifdef	__cplusplus
extern "C" {
#endif

    static inline void _pcglDrawArc(float x, float y, int startAngle, int endAngle, float w, float h, bool filled) {
        int perVertex = 2;

        int angle = endAngle - startAngle;
        GLfloat* vertices = (GLfloat*) calloc(angle * perVertex + 2, sizeof (GLfloat));

        for (int i = 0; i <= angle * perVertex; i += perVertex) {
            int currentAngle = i / perVertex + startAngle;

            vertices[i + 0] = x + (cos(DEGREES_TO_RADIANS(currentAngle)) * w);
            vertices[i + 1] = y + (sin(DEGREES_TO_RADIANS(currentAngle)) * h);
        }

        glDisableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glDrawArrays(filled ? GL_TRIANGLE_FAN : GL_LINE_STRIP, 0, angle + 1);
        glDisableClientState(GL_VERTEX_ARRAY);

        if (vertices != NULL) {
            free(vertices);
            vertices = NULL;
        }
    }

    static inline void pcglDrawArc(float x, float y, int startAngle, int endAngle, float w, float h) {
        _pcglDrawArc(x, y, startAngle, endAngle, w, h, false);
    }

    static inline void pcglDrawOval(float x, float y, float w, float h) {
        pcglDrawArc(x, y, 0, 360, w, h);
    }

    static inline void pcglDrawCircle(float x, float y, float r) {
        pcglDrawArc(x, y, 0, 360, r, r);
    }

    static inline void drawLine(float x1, float y1, float x2, float y2) {
        GLfloat* vertices = (GLfloat*) calloc(4, sizeof (GLfloat));
        vertices[0] = x1;
        vertices[1] = y1;
        vertices[2] = x2;
        vertices[3] = y2;

        glDisableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_LINES, 0, 4);

        free(vertices);
    }

    static inline void pcglDrawRect(float x1, float y1, float x2, float y2) {
        GLfloat* vertices = (GLfloat*) calloc(16, sizeof (GLfloat));
        vertices[0] = x1;
        vertices[1] = y1;
        vertices[2] = x2;
        vertices[3] = y1;
        vertices[4] = x2;
        vertices[5] = y1;
        vertices[6] = x2;
        vertices[7] = y2;
        vertices[8] = x2;
        vertices[9] = y2;
        vertices[10] = x1;
        vertices[11] = y2;
        vertices[12] = x1;
        vertices[13] = y2;
        vertices[14] = x1;
        vertices[15] = y1;

        glDisableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_LINES, 0, 8);
        glDisableClientState(GL_VERTEX_ARRAY);

        free(vertices);
    }

    static inline void pcglDrawRoundRect(float x1, float y1, float x2, float y2, float rw, float rh, bool filled) {
        float b = y1;
        float t = y2;
        float l = x1;
        float r = x2;

        float bi = b + rh;
        float ti = t - rh;
        float li = l + rw;
        float ri = r - rw;

        int perVertex = 2;
        int nvertices = 360 + 1;
        GLfloat* vertices = (GLfloat*) calloc(nvertices * perVertex + 2, sizeof (GLfloat));

        int i = 0;
        for (i = 0; i < 90 * perVertex; i += perVertex) { //top right
            //        int currentAngle = i / perVertex + startAngle;
            int currentAngle = i / perVertex;

            vertices[i + 0] = (GLfloat) (ri + (cos(DEGREES_TO_RADIANS(currentAngle)) * rw));
            vertices[i + 1] = (GLfloat) (ti + (sin(DEGREES_TO_RADIANS(currentAngle)) * rh));
        }
        for (; i < 180 * perVertex; i += perVertex) { //top left
            int currentAngle = i / perVertex;

            vertices[i + 0] = (GLfloat) (li + (cos(DEGREES_TO_RADIANS(currentAngle)) * rw));
            vertices[i + 1] = (GLfloat) (ti + (sin(DEGREES_TO_RADIANS(currentAngle)) * rh));
        }
        for (; i < 270 * perVertex; i += perVertex) { //bottom left
            int currentAngle = i / perVertex;

            vertices[i + 0] = (GLfloat) (li + (cos(DEGREES_TO_RADIANS(currentAngle)) * rw));
            vertices[i + 1] = (GLfloat) (bi + (sin(DEGREES_TO_RADIANS(currentAngle)) * rh));
        }
        for (; i < 360 * perVertex; i += perVertex) { //bottom right
            int currentAngle = i / perVertex;

            vertices[i + 0] = (GLfloat) (ri + (cos(DEGREES_TO_RADIANS(currentAngle)) * rw));
            vertices[i + 1] = (GLfloat) (bi + (sin(DEGREES_TO_RADIANS(currentAngle)) * rh));
        }
        vertices[720] = r;
        vertices[721] = ti;

        //    glDisableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glDrawArrays(filled ? GL_TRIANGLE_FAN : GL_LINE_STRIP, 0, nvertices);
        //    glDisableClientState(GL_VERTEX_ARRAY);

        if (vertices != NULL) {
            free(vertices);
            vertices = NULL;
        }
    }

    static inline void pcglFillRect(float x1, float y1, float x2, float y2) {
        int nvertices = 8;
        GLfloat* vertices = (GLfloat*) calloc(nvertices, sizeof (GLfloat));
        vertices[0] = x1;
        vertices[1] = y1;
        vertices[2] = x2;
        vertices[3] = y1;
        vertices[4] = x2;
        vertices[5] = y2;
        vertices[6] = x1;
        vertices[7] = y2;

        glDisableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_TRIANGLE_FAN, 0, nvertices / 2);
        glDisableClientState(GL_VERTEX_ARRAY);

        free(vertices);
    }

    static inline void pcglFillArc(float x, float y, int startAngle, int endAngle, float w, float h) {
        _pcglDrawArc(x, y, startAngle, endAngle, w, h, true);
    }

    static inline void drawCoverSuperior(float x1, float y1, float x2, float y2, float rw, float rh, bool filled) {
        float t = y1;
        float b = y2;
        float l = x1;
        float r = x2;

        float bi = t + rh;
        float ti = b - rh;
        float li = l + rw;
        float ri = r - rw;

        int perVertex = 2;
        int nvertices = 180 + 1;
        GLfloat* vertices = (GLfloat*) calloc(nvertices * perVertex, sizeof (GLfloat));

        int i = 0;
        for (i = 0; i < 90 * perVertex; i += perVertex) { //top right
            int currentAngle = i / perVertex;
            float angleRadian = DEGREES_TO_RADIANS(currentAngle);
            float cosx = cos(angleRadian);
            float sinx = sin(angleRadian);
            float height = (t > b) ? (t - b) : (b - t);

            vertices[i + 0] = (GLfloat) (ri + (cosx * (r - ri)));
            vertices[i + 1] = (GLfloat) (b  - (sinx * (height)));
        }
        for (; i < 180 * perVertex; i += perVertex) { //top right
            int currentAngle = i / perVertex;
            float angleRadian = DEGREES_TO_RADIANS(currentAngle);
            float cosx = -cos(angleRadian);
            float sinx = sin(angleRadian);
            float height = b-t;

            vertices[i + 0] = (GLfloat) (li - (cosx * (li - l)));
            vertices[i + 1] = (GLfloat) (b  - (sinx * (height)));
        }
        vertices[i + 0] = l;
        vertices[i + 1] = b;
//        vertices[0] = l;
//        vertices[1] = b;
//        vertices[i + 0] = ri;
//        vertices[i + 1] = t;
//        vertices[i + 2] = li;
//        vertices[i + 3] = t;
//        vertices[i + 4] = l;
//        vertices[i + 5] = b;
//        vertices[i + 6] = r;
//        vertices[i + 7] = b;

        //    glDisableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glDrawArrays(filled ? GL_TRIANGLE_FAN : GL_LINE_STRIP, 0, nvertices);
        //    glDisableClientState(GL_VERTEX_ARRAY);

        if (vertices != NULL) {
            free(vertices);
            vertices = NULL;
        }
    }


#ifdef	__cplusplus
}
#endif

#endif	/* PCGLPRIMITIVES_H */

