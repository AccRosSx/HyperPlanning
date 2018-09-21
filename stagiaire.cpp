//
//  stagiaire.cpp
//  planning
//
//  Created by Birintha Srichuthesgaran on 17/09/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "stagiaire.hpp"
#include "personnage.hpp"

using namespace std;

Stagiaire :: Stagiaire (string n, string p,string b, char s, string adres,string domicile, string portable) //mets en parametres et il le construit
{
    
    nom = n ;
    prenom = p;
    birth = b;
    sexe = s;
    adresse = adres ;
    teldomicile = domicile;
    telportable = portable;
    cout<<"stagiare  est créé"<<endl;
    
}


Stagiaire::~Stagiaire()
{
    //Dtor
}

Stagiaire:: Stagiaire ()//constructeur 2 qui permet de faire l'inscription
{
    string n, p, b ;
    char s;
    string adres, domicile, portable;
    
   
    cout<<"\t\t\t\tVeuillez vous inscrire\n"<<endl;
    cout<<"Remplissez le formulaire\n"<<endl;

    cout<<"Saississez votre nom de famille ?"<<endl;
    cin>>n;
    cout<<"Saississez votre prénom ?"<<endl;
    cin>>p;
    nom = n;
    prenom = p;
    
    cout<<"Saississez votre date de naissance"<<endl;
    cin>>b;
    cout<<"Indiquez votre sexe 'M' = Masculin ou 'F' = Feminin "<<endl;
    cin>>s;
    birth = b;
    sexe = s;
    
    cout<<"Saississez votre adresse"<<endl;
    getline(cin, adres);
    adresse = adres;
    
    

   cout<<"Ainsi indiquez nous votre numero de telephone pour vous joindre"<<endl;
    cout<<" Saississez votre numéro de téléphone domicile"<<endl;
    cin>>domicile;
    teldomicile = domicile;
   
    
    cout<<" Saississez votre numéro de téléphone portable"<<endl;
    cin>>portable;
    telportable = portable;
  
    
}

void Stagiaire::afficher()
{
    cout<<"\t\t\t\tVotre Fiche d'inscription"<<endl;
    cout<< "Nom: "<<nom<<"\tPrénom: "<<prenom<<endl ;
    cout<< "Date de naissance: "<<birth<<endl ;
    cout<< "Adresse: "<<adresse<<endl ;
    cout<< "Téléphone Domicile :  "<<teldomicile<<endl ;
    cout<< "Téléphone Portable :  "<<telportable<<endl ;
    
}

/*void Stagiaire::information()
{
    birth = dobirth;
    sexe = s;
    adresse = adres ;
    teldomicile = domicile;
    telportable = portable;
    cout<< "Date of birth: "<< birth <<"\nSexe: "<<sexe<<"\nAdresse : "<<adresse<<endl;
    cout<<"\nTelephone domicile : "<<teldomicile<<"\nTelephone portable : "<<telportable<<endl ;
}
 */
//void Stagiaire::verificationinscription()


