//
//  stagiaire.cpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#include "stagiaire.hpp"
Stagiaire::Stagiaire()
{
    //cout<<"he is created"<<endl;
    
}

Stagiaire::~Stagiaire()
{
    //Dtor
}

Stagiaire::Stagiaire(string v_matricule, string v_nom, string v_prenom, string v_ville, string v_telDomicile, string v_telPortable, string v_nomRue, string v_codeP, string v_dteNaissance, string v_dteInscription, int v_numRue, char v_sexe,int v_numGrp, int id)
{
    matricule = v_matricule;
    nom = v_nom;
    prenom = v_prenom;
    telDomicile = v_telDomicile;
    telPortable = v_telPortable;
    nomRue = v_nomRue;
    numRue = v_numRue ;
    codeP = v_codeP ;
    ville =v_ville ;
    dteNaissance = v_dteNaissance;
    dteInscription = v_dteInscription ;
    sexe = v_sexe;
    idGroupe = v_numGrp ;
    
    
}

void Stagiaire::Saisie()
{
    vector<vector<string>> Vecteur;
    string n,p,tD,tP,nomR,cP, v, dteN, dteIns;
    int numR;
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
    cout<<"Saississez votre adresse"<<endl;
    cout<<"Saississez le numero de la rue"<<endl;
    cin>>numR;
    cout<<"Saississez le nom de la rue"<<endl;
    cin.ignore(256,' ');
    getline(cin,nomR);
    cout<<"Saississez le code postal"<<endl;
    cin>>cP;
    cout<<"Saississez la ville"<<endl;
    cin>>v;
    
    
    
    cout<<"Ainsi indiquez nous votre numero de telephone pour vous joindre"<<endl;
    cout<<" Saississez votre numéro de téléphone domicile"<<endl;
    cin>>tD;
    
    cout<<" Saississez votre numéro de téléphone portable"<<endl;
    cin>>tP;
    
    cout<<"saisir l'année d'inscription"<<endl;
    cin>>dteIns;
    

    
    

    nom = n;
    prenom = p;
    telDomicile = tD;
    telPortable = tP;
    nomRue = nomR;
    numRue = numR;
    codeP =  cP;
    ville = v ;
    dteNaissance = dteN;
    dteInscription = dteIns ;
    sexe = s;
    role = 0;
    
    //vector<vector<string>> Vecteur = {{ "nom", "prenom", "telDomicile", "telPortable", "nomRue", "numRue", "codeP", "ville", "dteNaissance", "sexe"}, { n, p, tD, tP, nomR, numR, cP, v, dteN,s}};
    for(int i = 0; i < 2; i++){
        Vecteur.push_back(vector<string>());
    }
    

    Vecteur[0].push_back("role");
    Vecteur[0].push_back("nom");
    Vecteur[0].push_back("prenom");
    Vecteur[0].push_back("telDomicile");
    Vecteur[0].push_back("telPortable");
    Vecteur[0].push_back("nomRue");
    Vecteur[0].push_back("numRue");
    Vecteur[0].push_back("codeP");
    Vecteur[0].push_back("ville");
    Vecteur[0].push_back("dteNaissance");
    Vecteur[0].push_back("dteinscription");
    Vecteur[0].push_back("sexe");
    
    Vecteur[1].push_back(to_string(role));
    Vecteur[1].push_back(n);
    Vecteur[1].push_back(p);
    Vecteur[1].push_back(tD);
    Vecteur[1].push_back(tP);
    Vecteur[1].push_back(nomR);
    Vecteur[1].push_back(to_string(numR));
    Vecteur[1].push_back(cP);
    Vecteur[1].push_back(v);
    Vecteur[1].push_back(dteN);
    Vecteur[1].push_back(dteIns);
    Vecteur[1].push_back(string(1,s));
    
    Mysql connexion;
    connexion.Insert("personne", Vecteur);
    id = connexion.GetId("personne");
   // cout << id << endl;
    
    
}

string Stagiaire::CréerMatricule()
{
    //cout<<dteInscription<<endl;
    if(id < 10){
        matricule = dteInscription + "000" + to_string(id);
    }
    else if(id < 100){
        matricule = dteInscription + "00" + to_string(id);
    }
    else if(id < 1000){
        matricule = dteInscription + "0" + to_string(id);
    }
    else{
        matricule = dteInscription + to_string(id);
    }
    cout << "voici votre Matricule : "<<matricule << endl;
    Affectation();
    return matricule;
    
}


void Stagiaire::Affectation()
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

void Stagiaire::AffectationGroupe()
{
    vector<vector<string>> Vecteur;
    
    if(role == 0)
    {
        if( id >0 || id < 10)
        {
            idGroupe = 1;
        }
        if( id >10 || id <20)
        {
            idGroupe = 2;
            
        }
        
    }
    
    for(int i = 0; i < 2; i++){
        Vecteur.push_back(vector<string>());
    }
    
    Vecteur[0].push_back("idGroupe");
    Vecteur[1].push_back(to_string(idGroupe));
    
    Mysql connexion;
    connexion.Update("personne", id, Vecteur);
}

void Stagiaire::RechercheCours(string Matiere)
{
    Mysql connexion;
    sql::ResultSet *res;
    res = connexion.stmt->executeQuery("SELECT `dateCours`,`heureDebut` FROM `cours` WHERE `idGroupe`=(SELECT `idGroupe` FROM personne WHERE `id`=1) AND `idMatiere`=(SELECT `id` FROM matiere WHERE `nom`='" + Matiere + "')");
    while (res->next()) {
        cout<<"la date du Cours "<< Matiere<<" : "<<endl;
        cout << res->getString("dateCours") << endl;

        cout<<"L'heure du Cours de "<< Matiere<< ":"<<endl;
        cout<< res->getInt("heureDebut")<<"h"<< endl;
        
         cout<<"\n"<<endl;
        // type may need to be different
    }
}

void Stagiaire::AfficherPlanningJournee(string Date, string matricule)
{
    Mysql connexion;
    sql::ResultSet *res;
    res = connexion.stmt->executeQuery("SELECT matiere.nom,cours.heureDebut,cours.heureFin,salle.numeroSalle,personne.nom AS 'prof'FROM cours JOIN matiere ON cours.idMatiere=matiere.id JOIN salle ON cours.idSalle=salle.id JOIN personne ON cours.idProfesseur=personne.id WHERE cours.dateCours='" + Date + "' AND cours.idGroupe=(SELECT `idGroupe` FROM personne WHERE `matricule`= " + matricule +") ORDER BY cours.heureDebut ASC");
    
    cout<<"Date :"<<Date<< endl;
    cout<<"\n"<<endl;
    
    while (res->next()) {
        cout<<"Matiere :"<< res->getString("nom") << endl;
      
        
        cout<<"TIME :"<< res->getString("heureDebut") <<"-"<<res->getString("heureFin")<<endl;

        
        cout<<"Salle :"<<res->getString("numeroSalle") << endl;

        
        cout<<"Professeur :"<<res->getString("prof") << endl;
        cout<<"\n"<<endl;

        // type may need to be different
    }
}


//Essaie des requetes

//SELECT `dateCours`,`heureDebut` FROM `cours` WHERE `idGroupe`=(SELECT `idGroupe` FROM personne WHERE `id`=1) AND `idMatiere`=1
/**SELECT matiere.nom,cours.heureDebut,cours.heureFin,salle.numeroSalle,personne.nom
 FROM cours
 JOIN matiere ON cours.idMatiere=matiere.id
 JOIN salle ON cours.idSalle=salle.id
 JOIN personne ON cours.idProfesseur=personne.id
 WHERE cours.dateCours='15/10/2018'*/


/**
 SELECT matiere.nom,cours.heureDebut,cours.heureFin,salle.numeroSalle,personne.nom AS 'prof'
 FROM cours
 JOIN matiere ON cours.idMatiere=matiere.id
 JOIN salle ON cours.idSalle=salle.id
 JOIN personne ON cours.idProfesseur=personne.id
 WHERE cours.dateCours='15/10/2018'
 ORDER BY cours.heureDebut ASC
 */
    
/*
    SELECT matiere.nom,cours.heureDebut,cours.heureFin,salle.numeroSalle,personne.nom AS 'prof'
    FROM cours
    JOIN matiere ON cours.idMatiere=matiere.id
    JOIN salle ON cours.idSalle=salle.id
    JOIN personne ON cours.idProfesseur=personne.id
    WHERE cours.dateCours='15/10/2018' AND cours.idGroupe=(SELECT `idGroupe` FROM personne WHERE `id`=2)
    ORDER BY cours.heureDebut ASC

*/
