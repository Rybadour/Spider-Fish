#ifndef SHIP_H
#define SHIP_H

// modified by jeff to adapt to sample

#include "Spider-Fish-Prefix.pch"

#include "Shader.h"
#include "Object.h"

using namespace std;

class Ship 
{
    public:
        static const float SPEED;

        Ship();
        void initialized();

        void update(int msTimeStep);

    void setPosition(float x, float y);
    void setAttitude(float angle);
    void setScale(float m);
    
    void draw();
    
    void setup();
    
    private:
        Object geometry;
    
// replace these with more sensible names
        float vX; // pixels/sec
        float vY; // pixels/sec
    
        float pX, pY;
        float angle;

        float overflowX_;
        float overflowY_;
};

#endif // SHIP_H