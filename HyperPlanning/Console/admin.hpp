//
//  admin.hpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#ifndef admin_hpp
#define admin_hpp

#include <stdio.h>
#include <string>
#include "personne.hpp"
#include "Mysql.hpp"
using namespace std;

class Admin: Personne
{
public:
   virtual string CréerMatricule();
    void Affectation();
    void Saisie(); 
};

#endif /* admin_hpp */
