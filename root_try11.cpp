//
//  root_try11.cpp
//  
//
//  Created by Fasya Khuzaimah on 25.09.19.
//

{
    TFile* myfile = new TFile("myfile.root");
    
    //allocate the spaces for the branches
    int eventno;
    int version;
    int npoints;
    double px[100],py[100],pz[100];
    bool isgood[100];
    
    TTree *mytree;
    myfile->GetObject("mytree",mytree); //get the tree object
    
    //connect the spaces with branches
    mytree->SetBranchAddress("eventno",&eventno);
    mytree->SetBranchAddress("version",&version);
    mytree->SetBranchAddress("npoints",&npoints);
    mytree->SetBranchAddress("px",px);
    mytree->SetBranchAddress("py",py);
    mytree->SetBranchAddress("pz",pz);
    mytree->SetBranchAddress("isgood",isgood);
    
    //Do our little analysis work!
    int count=0;
    for(int evt=0;evt<mytree->GetEntries();evt++){
        mytree->GetEntry(evt);
        
        int count_pts = 0;
        for(int i=0;i<npoints;i++)
            if (isgood[i]) count_pts++;
        if (count_pts>10) count++;
    }
    printf("count = %d\n",count);
}

//TChain: for splitting my result into several ROOT files
//TChain* chn = new TChain("mytree");
//chn->Add("file1.root");
//chn->Add("file2.root");
//chn->Add("file3.root");
//or
//chn->Add("file*.root");
