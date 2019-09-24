//
//  root_try7.cpp
//  
//
//  Created by Fasya Khuzaimah on 15.09.19.
//

{
    TH2F* h2d = new TH2F("h2d","a 2d histogram",20,-5.,5.,20,-5.,5.);
    TRandom3 rnd(1234);
    for(int j=0;j<10000;j++) h2d->Fill(rnd.Gaus(0.,1.),rnd.Gaus(0.,1.));
    //h2d->Draw();
    //h2d->Draw("box");
    //h2d->Draw("lego");
    h2d->Draw("lego2");
    //h2d->Draw("cont");
    //h2d->Draw("surf");
    //h2d->Draw("surf4");
}
