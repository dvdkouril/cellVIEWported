#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class cellVIEWportedApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void cellVIEWportedApp::setup()
{
}

void cellVIEWportedApp::mouseDown( MouseEvent event )
{
}

void cellVIEWportedApp::update()
{
}

void cellVIEWportedApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( cellVIEWportedApp, RendererGl )
