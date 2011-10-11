#include "Shader.h"
using namespace std;


Shader::Shader() : program(0), shaders(vector<GLuint>()) 
{
        // do not create program here, because it will be initialized before gl context
//    program = glCreateProgram();
}

Shader::~Shader() 
{
    if (program)
        glDeleteProgram(program);
    // run through shaders to delete them
}

bool Shader::compile(const string &file, GLenum shaderType)
{
	ifstream shaderFile;
    
	shaderFile.open(file.c_str(), ios::binary);
	stringstream in;
	in << shaderFile.rdbuf();
	string source(in.str());
	
    // should check for read errors... 
    
    const char *str = source.c_str();

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &str, NULL);
    glCompileShader(shader);
		
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		
    if (status == GL_FALSE) 
    {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        
        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);
        
        const char *strShaderType = NULL;
        switch(shaderType)
        {
            case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
            case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
            case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
        }
        
        std::cerr << "Compile failure in " << strShaderType << " shader: " << strInfoLog << std::endl;
        
        delete[] strInfoLog;
        glDeleteShader(shader);
        
        return false;
    }
    
    shaders.push_back(shader);
    
	return true;
}

bool Shader::link()
{
    program = glCreateProgram();
    if (!program) {
        std::cerr << "Program handle invalid." << std::endl;
        return false;
    }
	
	glLinkProgram(program);
	
	GLint status;
	
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
		
		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
		
		std::cerr << "Linker failure: " << strInfoLog << std::endl;
		
		delete[] strInfoLog;
		
		return false;
	}
	return true;
}

void Shader::use()
{
    glUseProgram(program); 
}

void Shader::unuse()
{
    glUseProgram(0); 
}

int Shader::uniformLocation(const char *name)
{    
    return glGetUniformLocation(this->program, name);
}

/* 
 std::string GetInfoLog(GLuint obj)
 {
 std::string log;
 GLint status, count;
 GLchar *error;
 GLenum which = glIsShader(obj) ? GL_COMPILE_STATUS : GL_LINK_STATUS;
 
 void (*GetProg)(GLuint, GLenum, GLint*);
 void (*GetProgInfo)(GLuint, GLsizei, GLsizei*, GLchar*);
 
 bool swap = (bool)glIsShader(obj);
 GetProg = swap ? glGetShaderiv : glGetProgramiv;
 GetProgInfo = swap ? glGetShaderInfoLog : glGetProgramInfoLog;
 
 GetProg(obj, which, &status);
 if (!status)
 {
 GetProg(obj, GL_INFO_LOG_LENGTH, &count);
 if (count > 0)
 {
 GetProgInfo(obj, count, NULL, (error = new char[count+1]));
 log = error;
 delete[] error;
 }
 }	
 
 return log;
 }*/