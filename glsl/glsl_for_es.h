#ifndef GLSL_FOR_ES
#define GLSL_FOR_ES
#include <stdio.h>
#include <GL/gl.h>

#include <string.h>
#ifdef __cplusplus
extern "C" {
#endif
__attribute__((visibility("default"))) extern char *GLSLtoGLSLES(char *glsl_code, GLenum glsl_type, uint essl_version);
__attribute__((visibility("default"))) extern int getGLSLVersion(const char* glsl_code);
#ifdef __cplusplus
}
#endif
#endif