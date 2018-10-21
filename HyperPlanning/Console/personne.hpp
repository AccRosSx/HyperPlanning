//
//  personne.hpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#ifndef personne_hpp
#define personne_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std; 
class Personne
{
public:
    Personne();
    ~Personne();
    virtual void Saisie() = 0;
    virtual string CréerMatricule() = 0;
    
    
protected:
    int id;
    int role;
    string matricule; 
    string motDePasse;
    string nom;
    string prenom;
    
    string telDomicile;
    string telPortable;
    
    string nomRue;
    int numRue;
    string codeP;
    string ville;
    
    string dteNaissance;
    char sexe;
};

#endif /* personne_hpp */
