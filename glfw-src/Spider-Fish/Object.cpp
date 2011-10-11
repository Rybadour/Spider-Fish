//
//  Object.cpp
//  Spider-Fish
//
//  Created by Jeffrey Drake on 11-09-29.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//
//  OpenGL Object

#include "Object.h"

Object::Object() : geometry(), object(0), shader() {
    // nothing to do
}

Object::Object(vector<glm::vec4> &geo) : geometry(geo), object(0), shader(), prototype(geo) {
    //...
}

void Object::setGeometry(const vector<glm::vec4> &geo)
{
    geometry = geo;
    prototype = geo;
}

void Object::transform(const glm::mat4 &M)
{
    BOOST_FOREACH(auto &v, geometry) {
        v = M * v; 
    }
}

void Object::reset()
{
    geometry = prototype;
}

void Object::commitPrototype()
{
    prototype = geometry;
}

void Object::upload()
{  
    glGenVertexArrays(1, &vao);
    glCheckError(__FILE__, __LINE__);
    glBindVertexArray(vao);
    glCheckError(__FILE__, __LINE__);
    
    glGenBuffers(1, &object);
    glCheckError(__FILE__, __LINE__);
    
    glCheckError(__FILE__, __LINE__);
    glBindBuffer(GL_ARRAY_BUFFER, object);
    cout << "Is buffer? " << (glIsBuffer(object) == GL_TRUE ? "YES" : "NO") << " on " << __LINE__ << endl;

    glCheckError(__FILE__, __LINE__);
    glBufferData(GL_ARRAY_BUFFER, sizeof(geometry), geometry.data(), GL_STATIC_DRAW);
    glCheckError(__FILE__, __LINE__);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glCheckError(__FILE__, __LINE__);
}

void Object::draw()
{
    shader.use();

/*    GLuint var = shader.uniformLocation("projectionMatrix");
    glUniformMatrix4fv(var, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    
    var = shader.uniformLocation("viewportTranslation");
    glUniformMatrix4fv(var, 1, GL_FALSE, glm::value_ptr(viewportTranslation));
  */  
//    glBindVertexArray(vao);
//    glBindBuffer(GL_ARRAY_BUFFER, object);
    glCheckError(__FILE__, __LINE__);
    cout << "Is buffer? " << (glIsBuffer(object) == GL_TRUE ? "YES" : "NO") << " on " << __LINE__ << endl;
    glCheckError(__FILE__, __LINE__);
//    glEnableVertexAttribArray(0);
    glCheckError(__FILE__, __LINE__);
 //   glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glCheckError(__FILE__, __LINE__);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glCheckError(__FILE__, __LINE__);
//    glDisableVertexAttribArray(0);
    glCheckError(__FILE__, __LINE__);
    
    shader.unuse();

}

void Object::print()
{
    int i = 0;
    BOOST_FOREACH(auto v, geometry)
    {
        cout << "Vertex " << i << "(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;
        i++;
    }
    
}