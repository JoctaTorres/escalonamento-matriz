#include <stdio.h>
#include <stdlib.h>
#define li 3
#define co 4

int main( int argc, char *argv[] )
{

    /*int li, co; // linha e coluna
    S:
    printf("\n DIGITE A DIMENSAO DA MATRIZ. \n LINHAS :: ");
    scanf(" %d", &li);
    printf(" COLUNA :: ");
    scanf(" %d", &co);
    if(li<co-1)
    {
        printf("\n NUMERO DE EQUACOES INSUFICIENTE. TENTE DE NOVO : ");
        getch();
        goto S;
    }

    system("cls");



    for(il=0 ; il<li ; il++ ) // lendo a matriz
    {
        for(ic=0; ic<co; ic++ )
        {
            printf("\n VALOR DO ELEMENTO [%d][%d] = ",il+1, ic+1);
            scanf(" %f", &matriz[il][ic]);
        }
    }

    system("cls");
    printf("\n A MATRIZ AMPLIADA DO SISTEMA :: \n");
    for(il=0 ; il<li ; il++ ) // imprimindo a matriz
    {
        printf("\n");
        for(ic=0; ic<co; ic++ )
        {
            //matriz[il][ic]=0;
            printf(" \t%.2f", matriz[il][ic]);
        }

    }*/


    double matriz[li][co];
    int il, ic; // ind.Linha e ind.Coluna
    int lo, ld, oc, n, ia;
    double laux[co];
    double aux, k;

    for(ia=1, il=0; il<li; il++)
    {
        for(ic=0; ic<co; ic++, ia++)
        {
            matriz[il][ic]=atof(argv[ia]);
        }
    }

    for(ic= 0, il=0; il<li; ic++, ++il) //**
    {

        if (matriz[il][ic]==0) // caso permuta
        {

            for(lo=il; lo<li; lo++) //acha na coluna um número não nulo
            {
                if(matriz[lo][ic]!=0)
                    ld=lo;
            }
            for(oc=0; oc<co; oc++) //realiza a permuta
            {
                laux[oc] = matriz[il][oc];
                matriz[il][oc] = matriz[ld][oc];
                matriz[ld][oc] = laux[oc];
            }

        }
        //coloca o um
        aux=matriz[il][ic];
        for(oc=ic; oc<co; oc++)
        {
            matriz[il][oc]/=aux;
        }
        //zera os demais elementos da coluna
        for (lo=il+1; lo<li; lo++)
        {
            k=-matriz[lo][ic];
            for(oc=ic; oc<co; oc++) //numa linha aux. copia e opera a linha sendo trabalhada
            {
                laux[oc] = matriz[il][oc];
                laux[oc]*=k;
                matriz[lo][oc]+=laux[oc];
            }
        }
    }
    printf("\n\n A MATRIZ ESCALONADA DO SISTEMA :: \n");
    for(il=0 ; il<li ; il++ ) // imprimindo a matriz
    {
        printf("\n");
        for(ic=0; ic<co; ic++ )
        {
            printf(" \t%.2f", matriz[il][ic]); //matriz[il][ic]=0;
        }
    }

    /*char r;
    printf("\n\n DESEJA REPETIR? [S/N] : ");
    scanf(" %c", &r); r=toupper(r);
    if(r=='S')
    {
        system("cls");
        goto S;
    }*/
    return 0;
}
