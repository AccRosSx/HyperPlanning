//
//  cours.hpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#ifndef cours_hpp
#define cours_hpp

#include <stdio.h>
#include "matiere.hpp"
#include "professeur.hpp"
#include "salle.hpp"
#include "groupe.hpp"
#include <string>

class Cours
{
public:
    Cours();
    ~Cours();
    
    int id;
    float dureeCours;
    Matiere matiereCours;
    Professeur profCours;
    Salle idSalleCours;
    Groupe idGroupeCours;
    string dateCours;
    string heureDebut;
    string heureFin;
    string typeCours;
 
};

#endif /* cours_hpp */
