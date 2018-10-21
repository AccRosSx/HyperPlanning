//
//  professeur.cpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#include "professeur.hpp"
Professeur :: Professeur()
{
    
}

Professeur :: ~Professeur()
{
    //dtor
}

string Professeur::CréerMatricule()
{
    matricule = nom + to_string(id);
    cout << "voici votre Matricule : "<<matricule << endl;
    Affectation();
    return matricule;
}

void Professeur::Saisie()
{
    vector<vector<string>> Vecteur;
    string n,p,dteN;
    int nbHeure;
    char s;
    
    cout<<"\t\t\t\tVeuillez vous inscrire\n"<<endl;
    cout<<"Remplissez le formulaire\n"<<endl;
    cout<<"Saississez votre nom de famille ?"<<endl;
    cin>>n;
    cout<<"Saississez votre prénom ?"<<endl;
    cin>>p;
    
    
    cout<<"Saississez votre date de naissance"<<endl;
    cin>>dteN;
    cout<<"Indiquez votre sexe 'M' = Masculin ou 'F' = Feminin "<<endl;
    cin>>s;
   
    
    cout<<"Saississez le nombre d'heure de cours"<<endl;
    cin>>nbHeure;
        
    nom = n;
    prenom = p;
    dteNaissance = dteN;
    nbHeureMax = nbHeure;
    sexe = s;
    role = 1 ;
    
    for(int i = 0; i < 2; i++){
        Vecteur.push_back(vector<string>());
    }
    
    Vecteur[0].push_back("role");
    Vecteur[0].push_back("nom");
    Vecteur[0].push_back("prenom");
    Vecteur[0].push_back("dteNaissance");
    Vecteur[0].push_back("sexe");
    Vecteur[0].push_back("nbHeureMax");
    
    Vecteur[1].push_back(to_string(role));
    Vecteur[1].push_back(n);
    Vecteur[1].push_back(p);
    Vecteur[1].push_back(dteN);
    Vecteur[1].push_back(string(1,s));
    Vecteur[1].push_back(to_string(nbHeure));
    
    Mysql connexion;
    connexion.Insert("personne", Vecteur);
    id = connexion.GetId("personne");
   
    // cout << id << endl;
    
    
}

void Professeur::Affectation()
{
    vector<vector<string>> Vecteur;
    
    
    
    for(int i = 0; i < 2; i++){
        Vecteur.push_back(vector<string>());
    }
    
    Vecteur[0].push_back("matricule");
    Vecteur[1].push_back(matricule);
    
    
    Mysql connexion;
    connexion.Update("personne", id, Vecteur);
    
    
    
    
}
