//
//  PDBLoader.hpp
//  cellVIEWported
//
//  Created by David Kouřil on 06/10/16.
//
//

#ifndef PDBLoader_hpp
#define PDBLoader_hpp

#define PROJECT_PATH "/Users/dvdthepmkr/Google Drive/projects/cellVIEW/cellVIEWported/"

class PDBLoader {
public:
    PDBLoader(std::string proteinName, bool loadFromRemote = false);
    //virtual ~PDBLoader();
    
    std::vector<float> loadAndParse();
    
private:
    std::string path;
    std::string url;
    
    bool parsePDBLine(std::string line, cinder::vec3 & pos);
};


#endif /* PDBLoader_hpp */
