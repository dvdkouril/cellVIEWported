//
//  SceneRenderer.hpp
//  cellVIEWported
//
//  Created by David Kouřil on 13/10/16.
//
//

#ifndef SceneRenderer_hpp
#define SceneRenderer_hpp

#include <iostream>
#include <map>

#include "SceneManager.hpp"

class SceneRenderer
{
public:
    SceneRenderer();
    
    void drawScene();
    
private:
    void loadAllShaders();
    
    SceneManager * sceneManager; // renderer will take the data from this
    //std::map<std::string, RenderTexture> renderTargets;
};

#endif /* SceneRenderer_hpp */
