
//
//  root_try10.cpp
//  
//
//  Created by Fasya Khuzaimah on 24.09.19.
//

{
    TFile *myfile = new TFile("myfile.root","recreate");
    
    int eventno;
    int version;
    int npoints;
    double px[100],py[100],pz[100];
    bool isgood[100];
    
    TTree *mytree = new TTree("mytree","this is a plain tree");
    mytree->Branch("eventno",&eventno,"eventno/I");
    mytree->Branch("version",&version,"version/I");
    mytree->Branch("npoints",&npoints,"npoints/I");
    mytree->Branch("px",px,"px[npoints]/D");
    mytree->Branch("py",py,"py[npoints]/D");
    mytree->Branch("pz",pz,"pz[npoints]/D");
    mytree->Branch("isgood",isgood,"isgood[npoints]/O");
    
    TRandom3 rnd;
    
    for(int evt=0;evt<1000;evt++){
        eventno = evt;
        version = 1234;
        npoints = (int)rnd.Uniform(1.,100.);
        for(int i=0;i<npoints;i++){
            px[i] = rnd.Gaus(0.,1.);
            py[i] = rnd.Gaus(0.,1.);
            pz[i] = rnd.Gaus(0.,1.);
            
            double R = sqrt(px[i]*px[i] + py[i]*py[i] + pz[i]*pz[i]);
            if (R<1.)   isgood[i] = true;
            else        isgood[i] = false;
        }
        mytree->Fill();
    }
    mytree->Write();
    myfile->Close();
}

//_file0->ls()
//mytree->StartViewer()
//mytree->SetFillColor(50); //fill histogram color
//mytree->Draw("px");
//mytree->Draw("isgood"); //draw boolean
//mytree->SetMarkerStyle(7);
//mytree->Draw("py:px","isgood") //draw py and px, also do selection with isgood selection

//mytree->Show(123) //show an event (event 123)
//mytree->GetEntries() //check how many events do we have
//mytree->Print() //printout the tree structure
//mytree->Scan("eventno:npoints:px[0]:isgood[0]") //scan over the data
//mytree->Scan("eventno:npoints:px[0]:isgood[0]","isgood[0]") //apply some selection cuts
