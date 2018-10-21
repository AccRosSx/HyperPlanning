//
//  stagiaire.hpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#ifndef stagiaire_hpp
#define stagiaire_hpp

#include <stdio.h>
#include<string>
#include "personne.hpp"
#include "Mysql.hpp"

using namespace std;

class Stagiaire : public Personne
{
public:
    Stagiaire();
    ~Stagiaire();
    Stagiaire(string v_matricule, string v_nom, string v_prenom, string v_ville, string v_telDomicile, string v_telPortable, string v_nomRue, string v_codeP, string v_dteNaissance, string v_dteInscription, int v_numRue, char v_sexe,int v_numGrp, int id);
    
    
    void Saisie();
    virtual string CréerMatricule();
    void Affectation();
    void AffectationGroupe();
    void RechercheCours(string Matiere);
    void AfficherPlanningJournee(string Date, string matricule);
    //int suppression(string matricule);
    
private:

    string dteInscription;
    int idGroupe;
};
#endif /* stagiaire_hpp */

