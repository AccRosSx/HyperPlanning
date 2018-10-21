//
//  matiere.hpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#ifndef matiere_hpp
#define matiere_hpp

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Matiere
{
public:
    Matiere();
    ~Matiere();
    
    int id;
    float nbHeureTD;
    float nbHeureTP;
    float nbHeureProjet;
    float nbHeureAmphi;
    string nomMatiere;
    vector<int> groupes;//plusieurs
    vector<int> enseignants;
    
};
#endif /* matiere_hpp */
