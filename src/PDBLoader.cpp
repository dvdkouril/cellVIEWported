//
//  PDBLoader.cpp
//  cellVIEWported
//
//  Created by David Kouřil on 06/10/16.
//
//

#include "PDBLoader.h"

#include <fstream>

PDBLoader::PDBLoader(std::string proteinName, bool loadFromRemote) {
    /*
     TODO: 
     - assemble path to .pdb file from the proteinName
     - if loadFromRemote => assemble URL for download and download via cURL
     - else just look at a certain folder (inside the project file there should be some default folder with pdbs)
     */
    
    if (loadFromRemote)
    {
        // cURL downloading of file from database
        this->url = "http://something";
        this->path = "downloaded/to/path/";
    }
    else
    {
        std::string path = "default/path/to/pdbs/";
        path += proteinName;
        path += ".pdb";
        
        this->path = path;
        this->url = "";
    }
}

std::vector<float> PDBLoader::loadAndParse() {
    
    std::vector<float> atomPositions;
    
    std::ifstream file(this->path);
    std::string line;
    while (std::getline(file, line)) {
        cinder::vec3 pos = parsePDBLine(line);
        // TODO: not every line will return atom position, need to have different function prototype that communicated that
        atomPositions.push_back(pos.x);
        atomPositions.push_back(pos.y);
        atomPositions.push_back(pos.z);
    }
    
    return std::vector<float>();
}

cinder::vec3 PDBLoader::parsePDBLine(std::string line) {
    // TODO: tokenize line, check if ATOM is first, if yes then look at position values in tokens
    //       convert strings to floats
    return cinder::vec3();
}