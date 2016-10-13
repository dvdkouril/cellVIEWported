//
//  SceneRenderer.cpp
//  cellVIEWported
//
//  Created by David Kouřil on 13/10/16.
//
//

#include "cinder/gl/gl.h"

#include "SceneRenderer.hpp"

SceneRenderer::SceneRenderer()
{
    //vbo setup?
//    mVao = gl::Vao::create();
//    gl::ScopedVao vaoScope(mVao);
//    
//    mVbo = gl::Vbo::create(GL_ARRAY_BUFFER, sizeof(float) * this->atomPositions.size(), this->atomPositions.data(), GL_STATIC_DRAW);
//    gl::ScopedBuffer scopedBuffer(mVbo);
//    gl::vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//    gl::enableVertexAttribArray(0);
    
}

void SceneRenderer::loadAllShaders()
{
//    try {
//        mShaderProg = gl::GlslProg::create(loadAsset("RenderProteins.vs"), loadAsset("RenderProteins.fs"));
//    } catch (const gl::GlslProgCompileExc& exc) {
//        //CI_LOG_E("Shader load failed: " << exc.what());
//        cout << "Error while loading shaders" << exc.what() << endl;
//        quit();
//    }
    std::cout << "Shaders successfully loaded, compiled and linked" << std::endl;
}

void SceneRenderer::drawScene()
{
    
    //gl::clear( Color( 0.8f, 0.8f, 0.8f ) );
    
    //    gl::setMatrices(mCamera);
    //
    //    {
    //        gl::ScopedGlslProg prog(mShaderProg);
    //
    //        gl::ScopedVao vaoScoped(this->mVao);
    //
    //        gl::setDefaultShaderVars();
    //        gl::pointSize(4.0f);
    //        gl::drawArrays(GL_POINTS, 0, this->atomPositions.size() / 3);
    //    }
}