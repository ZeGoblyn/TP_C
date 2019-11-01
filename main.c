#include <stdio.h>
#include <stdlib.h>

#define TAILLEMORP 3
#define CHARMORP1 'X'
#define CHARMORP2 'O'


void affichTab(char tableMorpyon[TAILLEMORP][TAILLEMORP]);

void initTabMorpion(char tableMorpyon[TAILLEMORP][TAILLEMORP]);

void tourJoueur(char tableMorpyon[TAILLEMORP][TAILLEMORP],char charMorp,int tourJoueur);

int Victoire(char tableMorpyon[TAILLEMORP][TAILLEMORP]);


int main()
{

    int test=0;

    char tableMorpyon[TAILLEMORP][TAILLEMORP];

    int tr=1;   //Mise en place d'un "pseudo booléen" pour l'alternance de tours


    /*for (i=0;i<TAILLEMORP; i++)     //Initialisation du tableau
    {
        for (j=0;j<TAILLEMORP;j++)
        {
            tableMorpyon[i][j]='_\n';
            printf("%c",tableMorpyon[i][j]);
        }
    }*/

    initTabMorpion(tableMorpyon);

    affichTab(tableMorpyon);



   // printf("%c",tableMorpyon[i][j]);

    do
    {
        if(tr==1)
        {
            tourJoueur(tableMorpyon,CHARMORP1, tr);
            tr=2;
        }else
        {
            tourJoueur(tableMorpyon,CHARMORP2, tr);
            tr=1;
        }
        affichTab(tableMorpyon);
        test=(Victoire(tableMorpyon));
        printf("test %d\n", test);

    }while(!test);

    printf("Joueur %d a perdu", tr);

    return 0;
}

void affichTab(char tableMorpyon[TAILLEMORP][TAILLEMORP]){

    int i,j;

    for(i=0;i<TAILLEMORP;i++){
            printf("|");
            for(j=0;j<TAILLEMORP;j++){
                printf(" %c |",tableMorpyon[i][j]);
            }
            printf("\n");
        }
}

void initTabMorpion(char tableMorpyon[TAILLEMORP][TAILLEMORP]){
    int i, j;
    for(i=0;i<TAILLEMORP;i++){
        for(j=0;j<TAILLEMORP;j++){
            tableMorpyon[i][j] = ' ';
        }
    }
}


void tourJoueur(char tableMorpyon[TAILLEMORP][TAILLEMORP],char charMorp,int tourJoueur)
//BUT attribuer les valeures x,y à la case du tableau équivalente pour inscrire une croix
//ENTREE coordonnées x/y
//SORTIE renvois des coordonnées au tableau principale
{
    int x,y;

    do
    {
        printf("Joueur %d Donner les coordonnees x du point a marquer (entre 1et 3)", tourJoueur);

        scanf("%d",&x);

        printf("Joueur %d Donner les coordonnees y du point a marquer (entre 1et 3)", tourJoueur);

        scanf("%d",&y);
    }while ((x<1 || x>3)||(y<1 || y>3));

    x=x-1;                      //On réduit les valeures de 1, le tableau commençant à 0

    y=y-1;

    tableMorpyon[x][y]=charMorp;

}



int Victoire(char tableMorpyon[TAILLEMORP][TAILLEMORP])
{
    int comptX, comptO;

    int i,j;

    comptX=0;

    comptO=0;

    for(i=0;i<TAILLEMORP;i++){      //Verification des lignes
        if (comptX!=3)
        {
            comptX=0;
        }
                           //Remise à 0 des variables après un chek ligne
        if (comptO!=3)
        {
            comptO=0;
        }
        for(j=0;j<TAILLEMORP;j++){
           if (tableMorpyon[i][j] == CHARMORP1)
           {
                comptX+=1;
           }else if (tableMorpyon[i][j] == CHARMORP2)
           {
               comptO+=1;
           }

        }
    }

    if (comptX==3)
    {
        return 1;
    }else if (comptO==3)
    {
        return 1;
    }

    for(j=0;j<TAILLEMORP;j++){      //Verification des colonnes
        if (comptX!=3)
        {
            comptX=0;
        }
                           //Remise à 0 des variables après un chek ligne
        if (comptO!=3)
        {
            comptO=0;
        }
        for(i=0;i<TAILLEMORP;i++){
           if (tableMorpyon[i][j] == CHARMORP1)
           {
                comptX+=1;
           }else if (tableMorpyon[i][j] == CHARMORP2)
           {
               comptO+=1;
           }

        }
    }

    if ((tableMorpyon[1][1]==CHARMORP1)&&(tableMorpyon[2][2]==CHARMORP1)&&(tableMorpyon[3][3]==CHARMORP1))   //Verification des diagonales
    {
        return 1;
    }else if ((tableMorpyon[3][1]==CHARMORP1)&&(tableMorpyon[2][2]==CHARMORP1)&&(tableMorpyon[1][3]==CHARMORP1))
    {
        return 1;
    }

    if ((tableMorpyon[1][1]==CHARMORP2)&&(tableMorpyon[2][2]==CHARMORP2)&&(tableMorpyon[3][3]==CHARMORP2))
    {
        return 1;
    }else if ((tableMorpyon[3][1]==CHARMORP2)&&(tableMorpyon[2][2]==CHARMORP2)&&(tableMorpyon[1][3]==CHARMORP2))
    {
        return 1;
    }

    if (comptX==3)      //Verification des comptes colonnes/lignes
    {
        return 1;
    }else if (comptO==3)
    {
        return 1;
    }

    return 0;
}


