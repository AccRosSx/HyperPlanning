//
//  admin.cpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#include "admin.hpp"


string Admin::CréerMatricule()
{
    matricule = nom + to_string(id);
    cout << "voici votre Matricule : "<<matricule << endl;
    Affectation(); 
    return matricule;
}

void Admin::Saisie()
{
    vector<vector<string>> Vecteur;
    string n,p,dteN;
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
    
    nom = n;
    prenom = p;
    dteNaissance = dteN;
    sexe = s;
    role = 2;
    //vector<vector<string>> Vecteur = {{ "nom", "prenom", "telDomicile", "telPortable", "nomRue", "numRue", "codeP", "ville", "dteNaissance", "sexe"}, { n, p, tD, tP, nomR, numR, cP, v, dteN,s}};
    for(int i = 0; i < 2; i++){
        Vecteur.push_back(vector<string>());
    }
    
    Vecteur[0].push_back("role");
    Vecteur[0].push_back("nom");
    Vecteur[0].push_back("prenom");
    Vecteur[0].push_back("dteNaissance");
    Vecteur[0].push_back("sexe");

    
    Vecteur[1].push_back(to_string(role));
    Vecteur[1].push_back(n);
    Vecteur[1].push_back(p);
    Vecteur[1].push_back(dteN);
    Vecteur[1].push_back(string(1,s));

    
    Mysql connexion;
    connexion.Insert("personne", Vecteur);
    id = connexion.GetId("personne");

    // cout << id << endl;
    
    
}

void Admin:: Affectation()
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
