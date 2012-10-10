/* 
 * File:   color.h
 * Author: paulocanedo
 *
 * Created on 30 de Agosto de 2012, 10:36
 */

#ifndef COLOR_H
#define	COLOR_H

#ifdef	__cplusplus
extern "C" {
#endif

    static vec4 pcglWhite      = {{1.0, 1.0, 1.0, 1.0}};
    static vec4 pcglRed        = {{1.0, 0.0, 0.0, 1.0}};
    static vec4 pcglGreen      = {{0.0, 1.0, 0.0, 1.0}};
    static vec4 pcglBlue       = {{0.0, 0.0, 1.0, 1.0}};
    static vec4 pcglCyan       = {{0.0, 1.0, 1.0, 1.0}};
    static vec4 pcglMagenta    = {{1.0, 0.0, 1.0, 1.0}};
    static vec4 pcglYellow     = {{1.0, 1.0, 0.0, 1.0}};
    static vec4 pcglLightGray  = {{0.8, 0.8, 0.8, 1.0}};
    static vec4 pcglGray       = {{0.5, 0.5, 0.5, 1.0}};
    static vec4 pcglDarkGray   = {{0.2, 0.2, 0.2, 1.0}};
    static vec4 pcglBlack      = {{0.0, 0.0, 0.0, 1.0}};
    
    static vec4 pcglCLightGray  = {{242/255.0, 241/255.0, 240/255.0, 1.0}};
    static vec4 pcglBootstrapBlue  = {{0.016, 0.612, 0.860, 1.0}};
    static vec4 pcglBootstrapGreen = {{0.275, 0.647, 0.275, 1.0}};


#ifdef	__cplusplus
}
#endif

#endif	/* COLOR_H */

