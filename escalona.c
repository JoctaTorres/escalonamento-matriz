#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] )
{
	int li, co;   // number of lines and columns
    int il, ic; // aux. variables for line and column
    int lo, ld, oc; // aux. variables for transposition of two lines
    double laux[co]; // auxiliary line for transposition
    int ia; //aux. variable for casting sting to double
    double aux, k; //aux. variables for solving the matrix
    
    li=atof(argv[1]); // first argv represents the number of lines
	co=atof(argv[2]); // second argv represents the number of lines
    double matrix[li][co];

    for(ia=1, il=0; il<li; il++) // string to double
    {
        for(ic=0; ic<co; ic++, ia++)
        {
            matrix[il][ic]=atof(argv[ia]);
        }
    }

    for(ic= 0, il=0; il<li; ic++, ++il) // main loop for solving the matrix
    {

        if (matrix[il][ic]==0) // transposition of two lines
        {

            for(lo=il; lo<li; lo++) //finds in the determined column a number different than zero
            {
                if(matrix[lo][ic]!=0)
                    ld=lo;
            }
            for(oc=0; oc<co; oc++) // transposition
            {
                laux[oc] = matrix[il][oc];
                matrix[il][oc] = matrix[ld][oc];
                matrix[ld][oc] = laux[oc];
            }

        }

        //setting the first not null element of the line as a one
        aux=matrix[il][ic];
        for(oc=ic; oc<co; oc++)
        {
            matrix[il][oc]/=aux;
        }

        //nulling the other elements of the column
        for (lo=il+1; lo<li; lo++)
        {
            k=-matrix[lo][ic];
            for(oc=ic; oc<co; oc++) //using an auxiliary line: copies and operate given line
            {
                laux[oc] = matrix[il][oc];
                laux[oc]*=k;
                matrix[lo][oc]+=laux[oc];
            }
        }
    }
    /*printf("\n\n SOLVED MATRIX :: \n"); //printing the matrix
    for(il=0 ; il<li ; il++ )
    {
        printf("\n");
        for(ic=0; ic<co; ic++ )
        {
            printf(" \t%.2f", matrix[il][ic]);
        }
    }*/
    return matrix;
}
