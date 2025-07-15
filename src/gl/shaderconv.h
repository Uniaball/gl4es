#ifndef _GL4ES_SHADERCONV_H_
#define _GL4ES_SHADERCONV_H_

#include "gles.h"
#include "program.h"

void set_uniforms_default_value(GLuint program, uniforms_declarations uniformVector, int uniformCount);
char* process_uniform_declarations(char* glslCode, uniforms_declarations uniformVector, int* uniformCount);
char* ConvertShaderVgpu(struct shader_s* shader_source);
char* ConvertShader(const char* pBuffer, int isVertex, shaderconv_need_t *need, int forwardPort);
char * ConvertShaderConditionally(struct shader_s * shader_source);

int isBuiltinAttrib(const char* name);
int isBuiltinMatrix(const char* name);

const char* hasBuiltinAttrib(const char* vertexShader, int Att);
const char* builtinAttribGLName(const char* name);
const char* builtinAttribInternalName(const char* name);
const char* gl4es_convertARB(const char* source, GLboolean isVertex, char** erro_msg, int* error_pos); 

#endif // _GL4ES_SHADERCONV_H_
