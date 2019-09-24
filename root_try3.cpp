//
//  root_try3.cpp
//  
//
//  Created by Fasya Khuzaimah on 13.09.19.
//

#include "root_try3.hpp"
{
    gSystem->Load("libMathMore");
    
    TF1 *l1 = new TF1("l1","ROOT::Math::legendre(1,x)",-1.,1.);
    TF1 *l2 = new TF1("l2","ROOT::Math::legendre(2,x)",-1.,1.);
    TF1 *l3 = new TF1("l3","ROOT::Math::legendre(3,x)",-1.,1.);
    
    l1->Draw();
    l2->Draw("same");
    l3->Draw("same");
}
