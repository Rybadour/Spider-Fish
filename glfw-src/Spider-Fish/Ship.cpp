#include "Ship.h"

#include "resources.h"

// Constant
const float Ship::SPEED = 100; // pixels/sec

Ship::Ship() : angle(0), vX(0), vY(0), pX(0), pY(0), overflowX_(0), overflowY_(0), geometry()
{
//    const float scale = 10.0;
//     float vertexPositions[] = { scale * cos(M_PI/2), scale*sin(M_PI/2), 0, 1,
//                                scale*cos(M_PI*11.0/6.0), scale*sin(M_PI*11.0/6.0), 0, 1,
  //                              scale*cos(M_PI*7.0/6.0), scale*sin(M_PI*7.0/6.0), 0, 1};
/*    const float vertexPositions[] = {
        10.0f, 10.0f, 0.0f, 1.0f,
        790.0f, 590.0f, 0.0f, 1.0,
        790.0f, 10.0f, 0.0f, 1.0,
    };


    glGenBuffers(1, &shipGeometry);
    glBindBuffer(GL_ARRAY_BUFFER, shipGeometry);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
  */
    
   

}

void Ship::setup()
{
    vector<glm::vec4> geo;

    geo.push_back(glm::vec4(cos(M_PI/2.0), sin(M_PI/2), 0, 1));
    geo.push_back(glm::vec4(cos(M_PI*7.0/6.0), sin(M_PI*7.0/6.0), 0, 1));
    geo.push_back(glm::vec4(cos(M_PI*11.0/6.0), sin(M_PI*11.0/6.0), 0, 1));


    
    geometry = geo;
    
//    geometry.transform(glm::scale(glm::mat4(1.0), glm::vec3(40, 40, 0)));
    geometry.commitPrototype();
    
    Shader shader;
    shader.compile(resourcePathFor("ship.vertex"), GL_VERTEX_SHADER);
    shader.compile(resourcePathFor("ship.fragment"), GL_FRAGMENT_SHADER);
    if (!shader.link())
    {
        cout << "Could not link shader program." << endl;
    }
    
    geometry.shader = shader;
    
    geometry.upload();
    geometry.print();
 
}

void Ship::setPosition(float x, float y)
{
    pX = x;
    pY = y;
    
    geometry.reset();
    geometry.transform(glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0, 0, 1.0)));
    geometry.transform(glm::translate(glm::mat4(1.0f), glm::vec3(pX, pY, 0.0f)));
    
    geometry.upload();
    
    geometry.print();
}

void Ship::setAttitude(float theta)
{
    angle = theta;

    geometry.reset();
    geometry.transform(glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0, 0, 1.0)));
    geometry.transform(glm::translate(glm::mat4(1.0f), glm::vec3(pX, pY, 0.0f)));
    
    geometry.upload();

    geometry.print();
}


void Ship::draw()
{
    geometry.draw();
}


void Ship::initialized()
{
//    sprite_ = owner_->spriteManager->createSprite("ship.png");
//    sprite_->x = 200;
//    sprite_->y = 100;
}

/*
void Ship::handleEvent(SDL_Event* event)
{
    // Key Down events
    if (event->type == SDL_KEYDOWN)
    {
        switch (event->key.keysym.sym)
        {
            case SDLK_UP: veloY_ -= SPEED; break;
            case SDLK_DOWN: veloY_ += SPEED; break;
            case SDLK_RIGHT: veloX_ += SPEED; break;
            case SDLK_LEFT: veloX_ -= SPEED; break;
        }
    }

    // Key Up events
    else if (event->type == SDL_KEYUP)
    {
        switch (event->key.keysym.sym)
        {
            case SDLK_UP: veloY_ += SPEED; break;
            case SDLK_DOWN: veloY_ -= SPEED; break;
            case SDLK_RIGHT: veloX_ -= SPEED; break;
            case SDLK_LEFT: veloX_ += SPEED; break;
        }
    }
}*/

void Ship::update(int msTimeStep)
{
    // TODO: Refactored to something nicer
    overflowX_ += vX * ((float)msTimeStep/1000);
    overflowY_ += vY * ((float)msTimeStep/1000);

    if (overflowX_ >= 1 || overflowX_ <= -1)
    {
//        sprite_->x += floor(overflowX_);
        overflowX_ = overflowX_ - floor(overflowX_);
    }

    if (overflowY_ >= 1  || overflowY_ <= -1)
    {
//        sprite_->y += floor(overflowY_);
        overflowY_ = overflowY_ - floor(overflowY_);
    }
}