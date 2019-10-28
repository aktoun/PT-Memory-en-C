    #include "jeu.h"
    #include "menu.h"

    void menu (void){

      short int flag=1, flag2=1;
      int niveau=0;

      ChoisirEcran(1); /* Fond d'écran qui correspond à la page d'acceuil avec le bouton START */
      ChargerImage("./image/bg1.png",0,0,0,0,LONGUEUR,HAUTEUR);
      ChargerImage("./image/back.png",0,875,0,0,101,45);
      ChargerImage("./image/rule.png",1000,800,0,0,243,145);

      ChoisirEcran(2); /* 2e page qui nous mène vers le choix du niveau de jeu avec un bouton pour connaître le règlement */
      ChargerImage("./image/bg2.png",0,0,0,0,LONGUEUR,HAUTEUR);

      ChoisirEcran(0);
      CopierZone(1,0,0,0,LONGUEUR,HAUTEUR,0,0);

      ChoisirEcran(3); /* 3e page qui nous mène vers le règlement du jeu */
      ChargerImage("./image/regle.png",0,0,0,0,LONGUEUR,HAUTEUR);
      ChargerImage("./image/back.png",0,0,0,0,101,45);

      ChoisirEcran(4); /* fond d'écran pour le plateau de jeu */
      ChargerImage("./image/bg_game.png",0,0,0,0,LONGUEUR,HAUTEUR);

      ChoisirEcran(5); /* fond d'écran pour le plateau de jeu */
      ChargerImage("./image/bg_game.png",0,0,0,0,LONGUEUR,HAUTEUR);
      
      ChoisirEcran(6); /*contient un seul dos de carte, utilisé pour le re retournement des cartes */
      ChargerImage("./image/cardback.png",0,0,0,0,LONGUEUR_CARTE,HAUTEUR_CARTE);



      while (flag==1){

        if (SourisCliquee()){
          if ((_X>=X1_START && _X<=X2_START) && (_Y>=Y1_START && _Y<=Y2_START)){ /* Bouton START affiché qui redirige vers le choix du niveau de jeu */
            CopierZone(2,0,0,0,LONGUEUR,HAUTEUR,0,0); 
            flag=0; /* Permet de sortir de la boucle while et de passer à la suite du programme lorsque le joueur appuie sur START */

          }else if ((_X>=X1_REGLE && _X<=X2_REGLE) && (_Y>=Y1_REGLE && _Y<=Y2_REGLE)){
            CopierZone(3,0,0,0,LONGUEUR,HAUTEUR,0,0);
            flag=2;

            while (flag==2){
              if (SourisCliquee()){
                if ((_X>=X1_BACK && _X<=X2_BACK) && (_Y>=Y1_BACK && _Y<=Y2_BACK)){
                menu();
                flag=1;
                }
              }
            }

          } else if ((_X>=X1_EXIT && _X<=X2_EXIT) && (_Y>=Y1_EXIT && _Y<=Y2_EXIT)){ /* Bouton EXIT affiché qui quitte le jeu */
            flag=0;
            FermerGraphique();
            exit(0); /* Permet de stopper le programme pour quitter le jeu */
          }
        }
      }

      while (flag2==1){

        if (SourisCliquee()){
          if ((_X>=X1_FACILE && _X<=X2_FACILE) && (_Y>=Y1_FACILE && _Y<=Y2_FACILE)){ /*Bouton FACILE */
            niveau=1; /* Permet d'accéder au niveau FACILE du jeu avec 16 cartes */
          jeu_carte(niveau);
          } else if ((_X>=X1_MOYEN && _X<=X2_MOYEN) && (_Y>=Y1_MOYEN && _Y<=Y2_MOYEN)){ /*Bouton MOYEN */
            niveau=2; /* Permet d'accéder au niveau MOYEN du jeu avec 24 cartes */
          jeu_carte(niveau);
          } else if ((_X>=X1_DIFFICILE && _X<=X2_DIFFICILE) && (_Y>=Y1_DIFFICILE && _Y<=Y2_DIFFICILE)){ /*Bouton DIFFICILE */
            niveau=3; /* Permet d'accéder au niveau DIFFICILE du jeu avec 36 cartes */
          jeu_carte(niveau);
           } else {
          niveau=0;
          }

          if (SourisCliquee() && niveau!=0){ /* Vérifie que la valeur de niveau est changé afin de quitter la boucle while */
            flag2=0;
          }
        }
      }


    }
