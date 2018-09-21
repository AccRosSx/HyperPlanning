//
//  stagiaire.hpp
//  planning
//
//  Created by Birintha Srichuthesgaran on 17/09/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#ifndef stagiaire_hpp
#define stagiaire_hpp

#include <stdio.h>
#include <stdlib.h>
#include "personnage.hpp"
#include <string>

using namespace std;

class Stagiaire : public Personnage
{
    private :
        string matricule;
    
    protected :
        string nom;
        string prenom;
        string birth;
        char sexe;
    
        string dateinscription;
        string adresse;
        string teldomicile;
        string telportable;
    
        char groupe;
    
    public:
        Stagiaire(string n, string p,string b, char s, string adres,string domicile, string portable);
        ~Stagiaire();
        Stagiaire();
    void afficher();
    
    
    
};
#endif /* stagiaire_hpp */
