//
//  groupe.hpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#ifndef groupe_hpp
#define groupe_hpp

#include <stdio.h>
#include "stagiaire.hpp"
#include "matiere.hpp"

using namespace std;


class Groupe
{
public:
    Groupe();
    ~Groupe();
    
    int id;
    static const int tailleMaxGp = 35;
    vector<Matiere> matieres;
};

#endif /* groupe_hpp */
