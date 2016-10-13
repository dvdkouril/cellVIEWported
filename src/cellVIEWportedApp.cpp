#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/CameraUi.h"

#include "PDBLoader.h"
#include "SceneRenderer.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class cellVIEWportedApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    cellVIEWportedApp(); // I don't know if I can do this...
    
private: // only temporary, scene info will go into separate class
//    std::vector<float> atomPositions;
//    gl::VaoRef mVao;
//    gl::VboRef mVbo;
//    gl::GlslProgRef mShaderProg;
    SceneRenderer * sceneRenderer;
    
    CameraPersp mCamera;
    CameraUi mCameraUi;
};

cellVIEWportedApp::cellVIEWportedApp() : App()
{
    sceneRenderer = new SceneRenderer(); // TODO: delete this
}

void cellVIEWportedApp::setup()
{
    int major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    std::cout << "OpenGL version: " << major << " " << minor << std::endl;
    
    //mCamera.setEyePoint(vec3(50, 50, 50));
    mCamera.lookAt(vec3(50, 50, 50), vec3(0,0,0));
    mCameraUi = CameraUi(&mCamera, getWindow(), -1);
}

void cellVIEWportedApp::mouseDown( MouseEvent event )
{
}

void cellVIEWportedApp::update()
{
}

void cellVIEWportedApp::draw()
{
    this->sceneRenderer->drawScene();
}

CINDER_APP( cellVIEWportedApp, RendererGl )
