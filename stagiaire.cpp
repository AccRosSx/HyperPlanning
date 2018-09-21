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
#include "stagiaire.hpp"
#include "personnage.hpp"

using namespace std;

Stagiaire :: Stagiaire (string n, string p) //mets en parametres et il le construit
{
    
    nom = n ;
    prenom = p;
    
    cout<<"stagiare  est créé"<<endl;
    
}


Stagiaire::~Stagiaire()
{
    //Dtor
}

Stagiaire:: Stagiaire ()//cons 2
{
    string n, p;
    cout<<"Saississez votre nom de famille ?"<<endl;
    cin>>n;
    cout<<"Saississez votre prénom ?"<<endl;
    cin>>p;
    
    nom = n;
    prenom = p;
    
}

void Stagiaire::afficher()
{
    cout<< "Nom: "<<nom<<"\tPrénom: "<<prenom<<endl ;
}

void Stagiaire::information(string dobirth, char s, string adres,string domicile, string portable)
{
    birth = dobirth;
    sexe = s;
    adresse = adres ;
    teldomicile = domicile;
    telportable = portable;
    cout<< "Date of birth: "<< birth <<"\nSexe: "<<sexe<<"\nAdresse : "<<adresse<<endl;
    cout<<"\nTelephone domicile : "<<teldomicile<<"\nTelephone portable : "<<telportable<<endl ;
}

//void Stagiaire::verificationinscription()


