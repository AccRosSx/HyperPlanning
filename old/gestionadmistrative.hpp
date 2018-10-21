//
//  gestionadmistrative.hpp
//  planning
//
//  Created by Birintha Srichuthesgaran on 14/09/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#ifndef gestionadmistrative_hpp
#define gestionadmistrative_hpp

#include <stdio.h>
#include <stdlib.h>
#include "stagiaire.hpp"

class Admin : public  Personnage
{
    
public:
    Admin();
    ~Admin();
    void inscription(Stagiaire &s);
    
    
    
    
};

#endif /* gestionadmistrative_hpp */
