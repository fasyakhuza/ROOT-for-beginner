//
//  root_try8.cpp
//  
//
//  Created by Fasya Khuzaimah on 23.09.19.
//

{
    TF1* f1 = new TF1("f1","x+x^2+x^3+x^4+sin(5*pi*x)+exp(x)",0.,1.);
    f1->Draw();
    f1->Eval(0.5); //get the function value at x=0.5
    f1->Derivative(0.5) //get derivation at x=0.5
    f1->Integral(0.,1.) //integration in an interval, e.g. [0,1]
    f1->GetRandom() //generate a random number according to this function
    
    TH1F* h1 = new TH1F("h1","a histogram", 100, 0., 1.);
    for(int i=0; i<10000; i++) h1->Fill(f1->GetRandom()); //same with L18
    h1->FillRandom("f1",10000);
    h1->Draw();
        
    TF2* f2 = new TF2("f2","sin(x)*sin(y)",0,10,0,10);
    f2->SetFillColor(50);
    f2->Draw();
    f2->Draw("lego");
    f2->Draw("surf4");
        
    
}
