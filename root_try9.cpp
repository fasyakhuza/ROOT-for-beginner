//
//  root_try9.cpp
//  
//
//  Created by Fasya Khuzaimah on 23.09.19.
//
{
    TFile *f1 = new TFile("n1.root","recreate"); //declare for recreating new root file, named as n1.root //open a new ROOT file
    
    TNtuple *n1 = new TNtuple("n1","a n-tuple","x:y:z:alpha:beta:gamma"); //n1 is the name of ntuple
    TRandom3 rnd;
    float var[6]; //declare six column, named as "var" (kind of data for each event)
    for(int i=0; i<10000; i++){
        //fill x,y,z
        var[0] = rnd.Uniform(0.,1);
        var[1] = rnd.Gaus(0.,1.);
        var[2] = rnd.Exp(-1.);
        //fill alpha,beta,gamma
        var[3] = var[0]*var[1];
        var[4] = var[0]*var[2];
        var[5] = var[0]*var[1]*var[3];
        
        n1->Fill(var);
    }
    
    //save and close the root file
    n1->Write(); //write the ntuple
    f1->Close(); //close writing
    
    //n1->SetFillColor(50);
    //n1->Draw("x")
    //n1->Draw("y")
    //n1->Draw("z")
    //n1->Draw("alpha")
    //n1->Draw("beta")
    //n1->Draw("gamma")
    //n1->Draw("sin(x)")
    //n1->Draw("sin(y)")
    //n1->Draw("sin(x)*cos(y)")
    //n1->Draw("y","y>0.0")
    //n1->Draw("y","y>x+z")
    
    //n1->Draw("y")
    //n1->SetFillColor(38)
    //n1->Draw("y","y>x","same") //draw two histograms in same canvas
    //n1->SetMarkerStyle(7)
    //n1->Draw("x:y")
    //n1->Draw("x:alpha")
    
}

//when we run this cpp in root, we cannot acces n1 directly. So we need to read n1 back:
//TFile* f2 = new TFile("n1.root");
//TNtuple* n1;
//n1 = (TNtuple*)f2->Get("n1"); //make an object
//n1->Draw("x");
//f2->ls();

//Get (recreate) an empty new file
//TFile* f1 = new TFile("file.root","recreate");
//f1->mkdir("dir");
//f1->cd("dir");
//f1->GetCompressionFactor() //how good the compression works

//n1->StartViewer(); //viewers a n-tuple or tree (if already have ntuple/tree)
//TBrowser b
