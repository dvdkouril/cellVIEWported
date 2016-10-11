//
//  PDBLoader.cpp
//  cellVIEWported
//
//  Created by David Kouřil on 06/10/16.
//
//

#include "PDBLoader.h"

#include <fstream>
#include <curl/curl.h>

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
        
        CURL *curl;
        //CURLcode res;
        
        curl_global_init(CURL_GLOBAL_DEFAULT);
        
        curl = curl_easy_init();
    }
    else
    {
        std::string path = PROJECT_PATH;
        path += "assets/";
        path += proteinName;
        path += ".pdb";
        
        this->path = path;
        this->url = "";
    }
}

// TODO: this should probably go to some Utilities file/class/namespace...
std::vector<std::string> split(std::string line)
{
    std::vector<std::string> results;
    std::string::const_iterator end = line.end();
    std::string::const_iterator current = line.begin();
    std::string::const_iterator next = find(current, end, ' ');
    while (next != end)
    {
        results.push_back(std::string(current, next));
        current = next + 1;
        while(*current == ' ') current = current + 1;
        next = find(current, end, ' ');
    }
    results.push_back(std::string(current, next));
    return results;
}

std::vector<float> PDBLoader::loadAndParse() {
    
    std::vector<float> atomPositions;
    
    std::ifstream file(this->path);
    std::string line;
    while (std::getline(file, line)) {
        cinder::vec3 pos;
        bool isAtomPositionLine = parsePDBLine(line, pos);
        
        if (isAtomPositionLine)
        {
            atomPositions.push_back(pos.x * 0.1f);
            atomPositions.push_back(pos.y * 0.1f);
            atomPositions.push_back(pos.z * 0.1f);
        }
    }
    
    std::cout << "Successfully loaded protein with " << atomPositions.size() / 3 << " atoms" << std::endl;
    
    return atomPositions;
    //return std::vector<float>();
}

bool PDBLoader::parsePDBLine(std::string line, cinder::vec3 & pos) {
    // TODO: tokenize line, check if ATOM is first, if yes then look at position values in tokens
    //       convert strings to floats
    auto tokens = split(line);
    if (tokens[0] == "ATOM")
    {
        std::string xStr = tokens[6];
        std::string yStr = tokens[7];
        std::string zStr = tokens[8];
        
        pos.x = ::atof(xStr.c_str());
        pos.y = ::atof(yStr.c_str());
        pos.z = ::atof(zStr.c_str());
        
        return true;
    }
    
    return false;
}


