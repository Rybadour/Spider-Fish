#ifndef Shader_H
#define Shader_H

#include "Spider-Fish-Prefix.pch"

using namespace std;

class Shader {
private:
    GLuint program;
    vector<GLuint> shaders;
    
public:
    Shader();
    ~Shader();
    
    bool compile(const std::string &file, GLenum shaderType);
    bool link();
    void use();
    void unuse();
    
    int uniformLocation(const char *name);
};

#endif