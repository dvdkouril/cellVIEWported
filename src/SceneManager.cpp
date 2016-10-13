//
//  SceneManager.cpp
//  cellVIEWported
//
//  Created by David Kouřil on 13/10/16.
//
//

#include "SceneManager.hpp"
#include "PDBLoader.h"


SceneManager::SceneManager()
{
    
}

void SceneManager::loadDataset()
{
    PDBLoader loader("2hhb", false);
    /*this->atomPositions = */loader.loadAndParse();
}