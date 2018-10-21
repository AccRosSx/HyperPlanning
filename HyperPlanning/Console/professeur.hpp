//
//  professeur.hpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#ifndef professeur_hpp
#define professeur_hpp

#include <stdio.h>
#include "personne.hpp"
#include "matiere.hpp"
#include "Mysql.hpp"

class Professeur :public Personne
{
public:
    Professeur();
    ~Professeur();
    string CréerMatricule();
    void Saisie();
    void Affectation(); 

    Matiere matiere;
    int nbHeureMax;
    
};

#endif /* professeur_hpp */

