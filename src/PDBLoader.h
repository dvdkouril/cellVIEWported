//
//  PDBLoader.hpp
//  cellVIEWported
//
//  Created by David Kouřil on 06/10/16.
//
//

#ifndef PDBLoader_hpp
#define PDBLoader_hpp

class PDBLoader {
public:
    PDBLoader(std::string proteinName, bool loadFromRemote = false);
    virtual ~PDBLoader();
    
    std::vector<float> loadAndParse();
    
private:
    std::string path;
    std::string url;
    
    cinder::vec3 parsePDBLine(std::string line);
};


#endif /* PDBLoader_hpp */
