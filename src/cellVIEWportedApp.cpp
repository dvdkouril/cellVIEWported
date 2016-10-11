#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/CameraUi.h"

#include "PDBLoader.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class cellVIEWportedApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
private: // only temporary, scene info will go into separate class
    std::vector<float> atomPositions;
    gl::VaoRef mVao;
    gl::VboRef mVbo;
    gl::GlslProgRef mShaderProg;
    CameraPersp mCamera;
    CameraUi mCameraUi;
};

void cellVIEWportedApp::setup()
{
    int major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    std::cout << "OpenGL version: " << major << " " << minor << std::endl;
    
    //PDBLoader loader("2rcj", false);
    PDBLoader loader("2hhb", false);
    this->atomPositions = loader.loadAndParse();
    
    try {
        mShaderProg = gl::GlslProg::create(loadAsset("RenderProteins.vs"), loadAsset("RenderProteins.fs"));
    } catch (const gl::GlslProgCompileExc& exc) {
        //CI_LOG_E("Shader load failed: " << exc.what());
        cout << "Error while loading shaders" << exc.what() << endl;
        quit();
    }
    cout << "Shaders successfully loaded, compiled and linked" << endl;
    
    //vbo setup?
    mVao = gl::Vao::create();
    gl::ScopedVao vaoScope(mVao);
    
    mVbo = gl::Vbo::create(GL_ARRAY_BUFFER, sizeof(float) * this->atomPositions.size(), this->atomPositions.data(), GL_STATIC_DRAW);
    gl::ScopedBuffer scopedBuffer(mVbo);
    gl::vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    gl::enableVertexAttribArray(0);
    
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
	gl::clear( Color( 0.8f, 0.8f, 0.8f ) );
    
    gl::setMatrices(mCamera);
    
    {
        gl::ScopedGlslProg prog(mShaderProg);
    
        gl::ScopedVao vaoScoped(this->mVao);
    
        gl::setDefaultShaderVars();
        gl::pointSize(4.0f);
        gl::drawArrays(GL_POINTS, 0, this->atomPositions.size() / 3);
    }    
}

CINDER_APP( cellVIEWportedApp, RendererGl )
