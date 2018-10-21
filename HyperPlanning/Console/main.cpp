//
//  main.cpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 13/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "stagiaire.hpp"
#include "professeur.hpp"
#include "admin.hpp"

using namespace std;



int main(int argc, const char * argv[]) {
    int choice;
    
    cout << "\t\t\t\tBienvenue sur Myefrei!\n";
    cout << "Saississez votre role : Stagiaire 0,Professeur 1, Admin 2 \n";
    cin>>choice;
    
    switch (choice) {
        case 0:
        {

            Stagiaire Prout;
            Prout.Saisie();
            Prout.CréerMatricule();
            Prout.AffectationGroupe();
            Prout.RechercheCours("Maths");
            string date, matricule;
            cout<<"Quel jour voulez vous afficher?\n"; 
            cin>>date;
            cout<<"Saississez votre matricule?\n";
            cin>>matricule;
            
            Prout.AfficherPlanningJournee(date,matricule);
            break;
        }
        case 1:
        {
            Professeur Prout;
            Prout.Saisie();
            Prout.CréerMatricule();
            break;
        }
            

        case 2:
        {
            Admin Prout;
            Prout.Saisie();
            Prout.CréerMatricule();
            break;
        }
           
            
        default:
            break;
    }
    


    
    return 0;
}

