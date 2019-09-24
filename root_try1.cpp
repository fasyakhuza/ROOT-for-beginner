//
//  root_try1.cpp
//  
//
//  Created by Fasya Khuzaimah on 13.09.19.
//

#include "root_try1.hpp"
{
    TH1F *h1 = new TH1F("h1","A Random Histogram",100,0.,1.);
    TF1 *f1 = new TF1("f1","[0]+[1]*x+[2]*gaus(2)");
    f1->SetParameters(2.,-1.0,2.5,0.5,0.05);
    
    h1->FillRandom("f1",2000);
    
    h1->Fit("f1");
    
}
