//
//  Object.h
//  Spider-Fish
//
//  Created by Jeffrey Drake on 11-09-29.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//



#ifndef Spider_Fish_Object_h
#define Spider_Fish_Object_h

#include "Spider-Fish-Prefix.pch"

#include "Shader.h"

using namespace std;

class Object 
{
public:
    Object();
    Object(vector<glm::vec4> &geo);
    void setGeometry(const vector<glm::vec4> &geo);
    void transform(const glm::mat4 &M);
    void upload();
    void reset();
    void commitPrototype(); // sets prototype object to be the current transformed.
    void draw();
    void print(); // for debug
    Shader            shader; // hack for ship and expediency
private:
    vector<glm::vec4> geometry;
    vector<glm::vec4> prototype;
    GLuint            object;
    GLuint            vao;

};


#endif
