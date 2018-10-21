//
//  salle.hpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#ifndef salle_hpp
#define salle_hpp

#include <stdio.h>
#include <string>

using namespace std;


class Salle
{
public:
    Salle();
    ~Salle();
    
    int id;
    int nbPlaces;
    char batiment;
    int numeroSalle;
    string typeSalle;
};

#endif /* salle_hpp */
