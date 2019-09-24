//
//  root_try5.cpp
//  
//
//  Created by Fasya Khuzaimah on 13.09.19.
//

#include <TRandom3.h>

#define M_SIZE 500
void do_some_calc()
{
    double A[M_SIZE][M_SIZE],B[M_SIZE][M_SIZE],C[M_SIZE][M_SIZE];
    
    TRandom3 rnd;
    for(int i=0;i<M_SIZE;i++)
        for(int j=0;j<M_SIZE;j++){
            A[i][j]=rand(); B[i][j] = rnd.Uniform();
        }
    for(int i=0;i<M_SIZE;i++)
        for(int j=0;j<M_SIZE;j++){
            C[i][j]=0.;
            for(int k=0;k<M_SIZE;k++)
                C[i][j] += A[k][j]*B[i][k];
        }
}
void root_try5()
{for(int i=0;i<10;i++) do_some_calc();}
