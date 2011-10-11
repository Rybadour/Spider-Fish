

#include "SpiderFish.h"

using namespace std;

// globals because opengl doesn't do this anymore...
glm::mat4 viewportTranslation;       // maps the location of the world we want to look at
glm::mat4 projectionMatrix;     // maps the location to the -1 to +1 gl coords


void SpiderFish::reshape(int width, int height)
{
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    
    updateProjection();
//    projectionMatrix = glm::translate(projectionMatrix, glm::vec3(-width, -height, 0));
    
    // note: the 0,0 point seems to be in the middle...
}

void SpiderFish::updateProjection()
{
    int w, h;
    
    glfwGetWindowSize(&w, &h);
    
    // mid points
    float mx = (viewport.at(2) - viewport.at(0))/2 + viewport.at(0);
    float my = (viewport.at(3) - viewport.at(1))/2 + viewport.at(1);
    viewportTranslation = glm::translate(glm::mat4(1.0), glm::vec3(-mx, -my, 0));
    
    // scale
    float sx = w / (viewport.at(2) - viewport.at(0));
    float sy = h / (viewport.at(3) - viewport.at(1));
    
    projectionMatrix = glm::ortho<float>(0.0, w, 0.0, h, -1.0, 1.0);
    projectionMatrix = projectionMatrix * glm::scale(glm::mat4(1.0), glm::vec3(sx, sy, 1.0));
}

void SpiderFish::setView(float x1, float y1, float x2, float y2)
{
    viewport.at(0) = x1;
    viewport.at(1) = y1;
    viewport.at(2) = x2;
    viewport.at(3) = y2;
    
    updateProjection();
}

void SpiderFish::key(int k, int action)
{
    if( action != GLFW_PRESS ) return;
    
    switch (k) {
        case GLFW_KEY_ESC:
            //            running = 0;
            glfwCloseWindow();
            break;
        default:
            return;
    }
}

bool SpiderFish::setup()
{
    if (!glfwInit()) 
    {
        cerr << "Failed to initialize GLFW" << endl;
        return false;
    }
    
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);  
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
    glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE); 
    
    if (!glfwOpenWindow(800, 600, 8, 8, 8, 8, 24, 8, GLFW_WINDOW))
    {
        cerr << "Could not open a window" << endl;
        glfwTerminate();
        return false;
    }
    
    glfwSetWindowTitle("Spider Fish");
    glfwEnable(GLFW_KEY_REPEAT);
    glfwSwapInterval(1); // vsync
    
    RenderInfo();
	ship.setup();
//    ship.setPosition(400, 300);
//    ship.setAttitude(90);
    
    setView(0, 0, 800, 600);
	return true;
    
}

void glCheckError(const char *file, int line)
{
    GLenum e = glGetError();
    if (e != GL_NO_ERROR)
    {
        cout << "Error in " << file << ":" << line << ": ";
        switch (e)
        {
            case GL_INVALID_ENUM:
                cout << "Invalid Enum" << endl;
                break;
            case GL_INVALID_VALUE:
                cout << "Invalid Value" << endl;
                break;
            case GL_INVALID_OPERATION:
                cout << "Invalid Operation" << endl;
                break;
            case GL_OUT_OF_MEMORY:
                cout << "Out of Memory" << endl;
                break;
            default:
                cout << "Unknown error " << e << endl;

        }
    }
}

bool SpiderFish::loop()
{
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
    glCheckError(__FILE__, __LINE__);
    glClear(GL_COLOR_BUFFER_BIT);
    glCheckError(__FILE__, __LINE__);
    glClearDepth(1.0);
    glCheckError(__FILE__, __LINE__);
    glDepthFunc(GL_LESS);
    glCheckError(__FILE__, __LINE__);
    glClear(GL_DEPTH_BUFFER_BIT);
    glCheckError(__FILE__, __LINE__);
    glFrontFace(GL_CCW);
    glCheckError(__FILE__, __LINE__);
    glCullFace(GL_BACK);
    glCheckError(__FILE__, __LINE__);

    ship.draw();
    glCheckError(__FILE__, __LINE__);

    glfwSwapBuffers();
    
    if (!glfwGetWindowParam(GLFW_OPENED))
        return false;
    
    return true;
}



