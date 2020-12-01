#include <stdio.h>
#include <stdlib.h>
#include "interfaceGraphique.h"
#define NORD 0
#define EST 1
#define SUD 2
#define OUEST 3


/*Versionning :
 * V1 : Jeu fonctionnel (Niveau 1/2) Nb : Corrigé la fin du niveau
 * V2 : Apport de l'interface graphique + Ajout du Niveau 3 + Corrections de certains bugs
 * Nb : Optimisé les conditions de déplacement/Case d'arrivée
 * V3 : Implémentation des 6 derniers niveaux
 * V4 : Optimisation du bloc de condition avec Vx/Vy
 * V5 : Réorganisation du code avec des pointeurs
 * V6 : Mode d'édition
 */


int xJoueur=0;
int yJoueur=0;
unsigned int currentLvl=0;
unsigned int nbrLife=3;

char tab[8][7][7]={{{'o',' ','l','l','l','l','l'},
                     {'l',' ','#','#','#','#','l'},
                     {'l','#',' ','#','#','#','l'},
                     {'l',' ','#',' ','#',' ','l'},
                     {'l','#',' ','#',' ',' ','*'},
                     {'l','#','#','#','#','#','l'},
                     {'l','l','l','l','l','l','l'}},



                   { {'o','#',' ','#',' ',' ','l'},
                     {'l',' ','#',' ',' ',' ','l'},
                     {'l','#','#','#','#',' ','l'},
                     {'l','#','#','#','#',' ','l'},
                     {'l','#','#','#','#',' ','*'},
                     {'l','#','#','#','#',' ','l'},
                     {'l','l','l','l','l','l','l'}},



                   { {'o',' ',' ',' ',' ','#',' '},
                     {'#','#',' ',' ','l',' ',' '},
                     {' ',' ','#','#',' ',' ',' '},
                     {' ','#',' ','#',' ','#','l'},
                     {' ','l','l',' ','l',' ','*'},
                     {' ',' ','l','#',' ','#',' '},
                     {' ',' ','l',' ','l','#','#'}},

                   { {'o','#',' ',' ',' ','#',' '},
                     {' ','i','i',' ',' ',' ','l'},
                     {'#',' ','#','l',' ',' ','i'},
                     {' ',' ','l',' ','l','i','*'},
                     {' ','#',' ',' ','#','#','i'},
                     {' ','l',' ',' ',' ','#',' '},
                     {' ',' ',' ',' ',' ',' ','l'}},

                   { {'o',' ','i',' ',' ',' ','l'},
                     {' ','#','i',' ',' ',' ','i'},
                     {' ','i',' ','#','i','#','#'},
                     {'#',' ','i','#',' ','i','*'},
                     {'l',' ','i',' ',' ','#','i'},
                     {' ','#',' ',' ',' ',' ',' '},
                     {' ',' ',' ',' ','#',' ',' '}},


                   { {'o',' ','l',' ',' ',' ',' '},
                     {' ','#','i',' ',' ','#','#'},
                     {'l','i','l',' ',' ','#','l'},
                     {' ',' ','l','#','l',' ','*'},
                     {'#',' ','l',' ','i',' ','l'},
                     {'i','#',' ',' ','i',' ','l'},
                     {' ',' ',' ','#','i','i',' '}},



                   { {'o',' ',' ',' ','i','i','i'},
                     {' ','l','#',' ','i','l','i'},
                     {'#','l',' ',' ','l','i','i'},
                     {' ','l',' ',' ','l','i','*'},
                     {' ','l',' ',' ','l','i','i'},
                     {' ',' ',' ',' ',' ',' ',' '},
                     {' ','l',' ',' ','i','#',' '}},



                   { {'o',' ',' ',' ','*',' ',' '},
                     {' ',' ',' ',' ','*',' ',' '},
                     {' ',' ',' ',' ','*',' ',' '},
                     {'#','l','l','l','l','l','#'},
                     {'l','#','l','l','l','#','l'},
                     {'l','l','#','l','#','l','l'},
                     {'l','l','l','#','l','l','l'}}};


char saveTab[7][7];




void initImg()
{
    chargerImageBMP("./Img_Sococo/jeu_7.bmp");   //0
    chargerImageBMP("./Img_Sococo/jeu_8.bmp");   //1
    chargerImageBMP("./Img_Sococo/jeu_9.bmp");   //2
    chargerImageBMP("./Img_Sococo/jeu_10.bmp");  //3
    chargerImageBMP("./Img_Sococo/jeu_11.bmp");  //4
    chargerImageBMP("./Img_Sococo/jeu_12.bmp");  //5
    chargerImageBMP("./Img_Sococo/jeu_13.bmp");  //6
    chargerImageBMP("./Img_Sococo/jeu_14.bmp");  //7
    chargerImageBMP("./Img_Sococo/jeu_15.bmp");  //8
    chargerImageBMP("./Img_Sococo/jeu_16.bmp");  //9
    chargerImageBMP("./Img_Sococo/jeu_17.bmp");  //10
    chargerImageBMP("./Img_Sococo/jeu_18.bmp");  //11
    chargerImageBMP("./Img_Sococo/jeu_19.bmp");  //12
    chargerImageBMP("./Img_Sococo/jeu_20.bmp");  //13
    chargerImageBMP("./Img_Sococo/jeu_21.bmp");  //14
    chargerImageBMP("./Img_Sococo/jeu_28.bmp");  //15
    chargerImageBMP("./Img_Sococo/jeu_29.bmp");  //16
    chargerImageBMP("./Img_Sococo/jeu_30.bmp");  //17
    chargerImageBMP("./Img_Sococo/jeu_31.bmp");  //18
    chargerImageBMP("./Img_Sococo/jeu_32.bmp");  //19
    chargerImageBMP("./Img_Sococo/jeu_33.bmp");  //20
    chargerImageBMP("./Img_Sococo/jeu_34.bmp");  //21
    chargerImageBMP("./Img_Sococo/jeu_35.bmp");  //22
}


void initSave()
{
   for(int i=0;i<7;i++)
   {
       for(int j=0;j<7;j++)
       {
           saveTab[i][j]=tab[currentLvl][i][j];
       }
   }

}

int first_verif(unsigned int pos,unsigned int dim) //Fonction de verification pour empêcher le joueur de dépasser le tableau
{
    unsigned int check=0;
    if(dim==0)
    {
        if(pos>dim)
        {
            check=1;
        }
    }
    else
    {
        if(pos<dim)
        {
            check=1;
        }
    }
    return check;
}

int second_verif(unsigned int pos,unsigned int dim,unsigned int vx,unsigned int vy)//Verif pour empêcher les caisses de dépasser le tableau
{
    unsigned int check=0;
    if(dim==0)
    {
        if(pos+vx+vy>dim)
        {
            check=1;
        }
    }
    else
    {
        if(pos+vx+vy<dim)
        {
            check=1;
        }
    }
    return check;
}


void menu()
{
    effacerDessin();
    dessinerImage(900,900,1,1,19);
}


void gameOver()
{
    effacerDessin();
    dessinerImage(900,900,1,1,18);
}

void youWin()
{
    effacerDessin();
    dessinerImage(900,900,1,1,20);
}


void printLvl()
{



    //Affichage nombres de vie
    for (unsigned int i=0;i<nbrLife;i++)
    {
        dessinerImage(800-(i*100),900,0.222,0.222,17);
    }

    //Affichage map
    for(int i=8;i>1;i--)
    {
        for(int j=1;j<8;j++)
        {
            switch(tab[currentLvl][j-1][8-i])
            {
               case ' ': //dessinerRectangle(i*100,j*100,(i-1)*100,(j+1)*100,0,0,0,255,255,255);
                dessinerImage(i*100,(j+1)*100,0.0765,0.0765,2);
                break;
               case '#': //dessinerRectangle(i*100,j*100,(i-1)*100,(j+1)*100,0,0,0,0,225,225);
                dessinerImage(i*100,(j+1)*100,0.333,0.333,1);
                break;
               case 'l': //dessinerRectangle(i*100,j*100,(i-1)*100,(j+1)*100,0,0,0,0,255,0);
                dessinerImage(i*100,(j+1)*100,0.161,0.179,0);
                break;
               case 'o': //dessinerRectangle(i*100,j*100,(i-1)*100,(j+1)*100,0,0,0,255,0,0);
                dessinerImage(i*100,(j+1)*100,0.148,0.147,4);
                break;
               case '*': //dessinerRectangle(i*100,j*100,(i-1)*100,(j+1)*100,0,0,0,0,0,255);
                dessinerImage(i*100,(j+1)*100,1,1,3);
                break;
               case 'i':dessinerImage(i*100,(j+1)*100,1,1,22);
                break;
            }
        }
    }


    dessinerImage(100,900,1,1,16);
    dessinerImage(900,900,1,1,16);


    dessinerImage(400,900
                  ,0.6,0.6,currentLvl+5);
    dessinerImage(600,100,0.6,0.6,15);
    if (nbrLife==0)
    {
        effacerDessin();
        gameOver();
    }
    if (currentLvl>7)
    {
        effacerDessin();
        youWin();
    }
    if(currentLvl==7)
    {
        dessinerImage(400,400,0.5,0.5,21);
    }

    //La map est affichée


}







void restartLvl()
{
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            tab[currentLvl][i][j]=saveTab[i][j];
        }
    }

    xJoueur=0;
    yJoueur=0;

    nbrLife--;


    effacerDessin();
    printLvl();
}




void deplacerJoueur (int dir)
{
    int vx1=0,vx2=0,vy1=0,vy2=0,pos=0,dim=0;
    switch (dir)
    {
        case NORD  : /*if (tab[currentLvl][yJoueur-1][xJoueur] != 'l' && yJoueur>0)

                     {
                         if (tab[currentLvl][yJoueur-1][xJoueur] != '#')
                         {
                             tab[currentLvl][yJoueur][xJoueur]=' ';
                             yJoueur --;
                             tab[currentLvl][yJoueur][xJoueur]='o';
                         }
                         else if(tab[currentLvl][yJoueur-2][xJoueur]!='#' && tab[currentLvl][yJoueur-2][xJoueur]!='l' )
                         {
                             tab[currentLvl][yJoueur][xJoueur]=' ';
                             yJoueur --;
                             tab[currentLvl][yJoueur][xJoueur]='o';
                             tab[currentLvl][yJoueur-1][xJoueur]='#';
                         }
                     }*/
                     pos=yJoueur;
                     dim=0;
                     vy1=-1;
                     vy2=-2;
                     break;

        case EST   : /*if (tab[currentLvl][yJoueur][xJoueur+1] != 'l' && xJoueur<6)
                     {
                         if (tab[currentLvl][yJoueur][xJoueur+1] != '#')
                         {
                             tab[currentLvl][yJoueur][xJoueur]=' ';
                             xJoueur ++;
                             tab[currentLvl][yJoueur][xJoueur]='o';
                         }
                         else if(tab[currentLvl][yJoueur][xJoueur+2]!='#' && tab[currentLvl][yJoueur][xJoueur+2]!='l' && xJoueur+1<6)
                         {
                             tab[currentLvl][yJoueur][xJoueur]=' ';
                             xJoueur ++;
                             tab[currentLvl][yJoueur][xJoueur]='o';
                             tab[currentLvl][yJoueur][xJoueur+1]='#';
                         }
                     }*/
                     pos=xJoueur;
                     dim=6;
                     vx1=1;
                     vx2=2;
                     break;

        case SUD   : /*if (tab[currentLvl][yJoueur+1][xJoueur] != 'l' && yJoueur<6)
                     {
                         if (tab[currentLvl][yJoueur+1][xJoueur] != '#')
                         {
                             tab[currentLvl][yJoueur][xJoueur]=' ';
                             yJoueur ++;
                             tab[currentLvl][yJoueur][xJoueur]='o';
                         }
                         else if(tab[currentLvl][yJoueur+2][xJoueur]!='#'  && tab[currentLvl][yJoueur+2][xJoueur]!='l' && yJoueur+1<6)
                         {
                             tab[currentLvl][yJoueur][xJoueur]=' ';
                             yJoueur ++;
                             tab[currentLvl][yJoueur][xJoueur]='o';
                             tab[currentLvl][yJoueur+1][xJoueur]='#';
                         }
                     }*/
                     pos=yJoueur;
                     dim=6;
                     vy1=1;
                     vy2=2;
                     break;

        case OUEST : /*if (tab[currentLvl][yJoueur][xJoueur-1] != 'l' && xJoueur>0)

                     {
                         if (tab[currentLvl][yJoueur][xJoueur-1] != '#')
                         {
                             tab[currentLvl][yJoueur][xJoueur]=' ';
                             xJoueur --;
                             tab[currentLvl][yJoueur][xJoueur]='o';
                         }
                         else if(tab[currentLvl][yJoueur][xJoueur-2]!='#' && tab[currentLvl][yJoueur][xJoueur-2]!='l' && xJoueur-1>0)
                         {
                             tab[currentLvl][yJoueur][xJoueur]=' ';
                             xJoueur --;
                             tab[currentLvl][yJoueur][xJoueur]='o';
                             tab[currentLvl][yJoueur][xJoueur-1]='#';
                         }
                     }*/
                     pos=xJoueur;
                     dim=0;
                     vx1=-1;
                     vx2=-2;
                     break;
    }
       /*if(tab[currentLvl][yJoueur+vy1][xJoueur+vx1]=='i' && first_verif(pos,dim)==1)
       {
           restartLvl();
       }
       if (tab[currentLvl][yJoueur+vy1][xJoueur+vx1] != 'l' && first_verif(pos,dim)==1)

       {
           if (tab[currentLvl][yJoueur+vy1][xJoueur+vx1] != '#')
           {
               tab[currentLvl][yJoueur][xJoueur]=' ';
               yJoueur+=vy1;
               xJoueur+=vx1;
               tab[currentLvl][yJoueur][xJoueur]='o';
           }
           else if(tab[currentLvl][yJoueur+vy2][xJoueur+vx2]!='#' && tab[currentLvl][yJoueur+vy2][xJoueur+vx2]!='l' && second_verif(pos,dim,vx1,vy1)==1)
           {
               tab[currentLvl][yJoueur][xJoueur]=' ';
               yJoueur+=vy1;
               xJoueur+=vx1;
               tab[currentLvl][yJoueur][xJoueur]='o';
               tab[currentLvl][yJoueur+vy1][xJoueur+vx1]='#';
           }
       }

    if(tab[currentLvl][yJoueur][xJoueur+1]=='*')
    {
        currentLvl++;
        initSave();
        xJoueur=0;
        yJoueur=0;


    }*/
    if(first_verif(pos,dim)==1)
    {
        switch(tab[currentLvl][yJoueur+vy1][xJoueur+vx1])
        {
            case ' ' : tab[currentLvl][yJoueur][xJoueur]=' ';
                       yJoueur+=vy1;
                       xJoueur+=vx1;
                       tab[currentLvl][yJoueur][xJoueur]='o';
                       break;

            case 'l' : break;

            case '#' : if(tab[currentLvl][yJoueur+vy2][xJoueur+vx2]!='l' && tab[currentLvl][yJoueur+vy2][xJoueur+vx2]!='#' && tab[currentLvl][yJoueur+vy2][xJoueur+vx2]!='*' && second_verif(pos,dim,vx1,vy1)==1)
                       {
                            tab[currentLvl][yJoueur][xJoueur]=' ';
                            yJoueur+=vy1;
                            xJoueur+=vx1;
                            tab[currentLvl][yJoueur][xJoueur]='o';
                            tab[currentLvl][yJoueur+vy1][xJoueur+vx1]='#';
                       }
                       break;

            case 'i' : restartLvl();
                       break;

            case '*' : currentLvl++;
                       initSave();
                       xJoueur=0;
                       yJoueur=0;
                       break;
        }
    }
    effacerDessin();
    printLvl();
}


void toucheEnfoncee ( uint64_t a, uint64_t b, uint64_t c)
 {
        //printf("x=%d , y=%d\n",xJoueur,yJoueur);
  switch (a)
   {
    case 116 : deplacerJoueur (SUD);
               break;

    case 114 : deplacerJoueur (EST);
               break;

    case 111 : deplacerJoueur (NORD);
               break;

    case 113 : deplacerJoueur (OUEST);
               break;

    case   9 : arreterGestionEvenements ();
               break;

    case 27  : restartLvl();

               break;

    case 36  : effacerDessin();

               printLvl();

               break;
   }
 }



int main()
{
    creerFenetre ("Sococo",    // Titre de la fen�tre graphique
                   900      ,    // Largeur de la fen�tre graphique
                   900      );   // Hauteur de la fen�tre graphique

    specifierLimites (    900 ,        // Abscisse minimale
                          0 ,        // Abscisse maximale
                          900 ,        // Ordonn�e minimale
                          0 );      // Ordonn�e maximale
    specifierGestionnaire ( "TOUCHE ENFONCEE"    , toucheEnfoncee      );

    initImg();

    initSave();

    menu();


    gererEvenements ();


    detruireFenetre ();

    return 0;
}
