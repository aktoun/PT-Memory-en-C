#include "jeu.h"

void triche(int flag) { /* fonction du mode triche */

	while (flag==1){
	    if (ToucheEnAttente()) {	        
	        if (Touche()==XK_t) { /* defini la touche 't' */	        
	            CopierZone(0,9,0,0,LONGUEUR,HAUTEUR,0,0);
		        CopierZone(5,0,0,0,LONGUEUR,HAUTEUR,0,0);
		        flag=2;

	            while (flag==2) {
	                if (ToucheEnAttente()) {
	                    if (Touche()==XK_t) {
	                        while (SourisCliquee());
	                        CopierZone(9,0,0,0,LONGUEUR,HAUTEUR,0,0); /* revenir écran du jeu */
	                        flag=0;
	                    }
	                }
	            }
	        }
	    }
	}
}

void jeu_carte(int niveau){

	int paire, ligne, colonne;
	int i, j, k;
	int max;
	int image;
	int marge_y, marge_x;

	int coinx1,coiny1,coinx2,coiny2;
	int stockx1,stocky1,stockx2,stocky2;
	int stockagex1,stockagey1,stockagex2,stockagey2;
	int plateau[6][6];
	int plateau_etat[6][6];
	char tab_carte[50];
	

	int random_facile[16]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
	int random_moyen[24]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12};
	int random_difficile[36]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18};

	if (niveau==1){
		
		ligne=4;
		colonne=4;
		paire=8;
		marge_x=500;
		marge_y=150;
		max=paire*2;

		srand(time(NULL));
		for (i=0;i<4;i++){
    		for (j=0;j<4;j++){
        		k=(rand () % max);
   				plateau[i][j]= random_facile[k];
   				plateau_etat[i][j]=0;
        		for(;k<max;k++){
        	  		random_facile[k]=random_facile[k+1];
       			}
       			max=max-1;
      		}
    	}

	} else if (niveau==2){
		
		ligne=4;
		colonne=6;
		paire=12;
		marge_x=325;
		marge_y=125;
		max=paire*2;

		srand(time(NULL));
		for (i=0;i<4;i++){
    		for (j=0;j<6;j++){
    	    	k=(rand () % max);
   				plateau[i][j]= random_moyen[k];
   				plateau_etat[i][j]=0;
        		for(;k<max;k++){
          			random_moyen[k]=random_moyen[k+1];
       			}
       			max=max-1;
     	 	}
    	}
	} else if (niveau==3){
		
		ligne=6;
		colonne=6;
		paire=18;
		marge_x=350;
		marge_y=25;
		max=paire*2;

		srand(time(NULL));
		for (i=0;i<6;i++){
	    	for (j=0;j<6;j++){
	        	k=(rand () % max);
	        	plateau[i][j]= random_difficile[k];
	        	plateau_etat[i][j]=0;
	        	for(;k<max;k++){
	        		random_difficile[k]=random_difficile[k+1];
	        	}
	       		max=max-1;
	      	}
	    }
	}

		ChoisirEcran(4);
		for (i=0;i<ligne;i++){
			for (j=0;j<colonne;j++){		
				ChargerImage("./image/cardback.png", j*150+marge_x,i*150+marge_y,0,0,LONGUEUR_CARTE,HAUTEUR_CARTE);
			}
		}
	
		ChoisirEcran(5);
		for (i=0;i<ligne;i++){
			for (j=0;j<colonne;j++){
				snprintf (tab_carte,50,"./image/%d.png", plateau[j][i]);
				image=ChargerSprite(tab_carte);
				AfficherSprite(image, j*150+marge_x, i*150+marge_y);
				LibererSprite(image);
			}
		}

	ChoisirEcran(0);
	CopierZone(4,0,0,0,LONGUEUR,HAUTEUR,0,0);

	int score=0;
	int x1, y1, x2, y2;
	int coup=1;
	int flag2=1;
	int flag;

	int seconde=0;
	char time[100];
	unsigned long suivant;

	while (flag2==1){

		if (Microsecondes() > suivant){
			CopierZone(7,0,0,300,300,50,50,10);
			sprintf(time,"TIME : %3d", seconde);
			EcrireTexte(140,50,time,2);
			seconde++;
			suivant=Microsecondes() + DELTA;
		}

		while (score!=paire){

			if (ToucheEnAttente()) {	        
	        	if (Touche()==XK_t) {
					flag=1;
					triche(flag);
				}
			}

			while (coup==1){
				if (SourisCliquee()){
					for (coiny1=marge_x,i=0;i<ligne;i++,coiny1+=150){
						for (coinx1=marge_y,j=0;j<colonne;j++,coinx1+=150){
							y1=i;
							x1=j;
							if ((_X <= ( marge_x+y1*ESPACE_CARTE_L) + LONGUEUR_CARTE ) && (_X >= marge_x+y1*ESPACE_CARTE_L)){
								if ((_Y <= ( marge_y+x1*ESPACE_CARTE_H) + LONGUEUR_CARTE ) && (_Y >= marge_y+x1*ESPACE_CARTE_H)){
									CopierZone(5,0, marge_x+y1*ESPACE_CARTE_L, marge_y+x1*ESPACE_CARTE_H, LONGUEUR_CARTE,HAUTEUR_CARTE, marge_x+y1*ESPACE_CARTE_L, marge_y+x1*ESPACE_CARTE_H);
									plateau_etat[x1][y1]=1;
									coup++;
									stockagey1=coiny1;
									stockagex1=coinx1;
									stockx1=i;
									stocky1=j;
									printf("%d\n", plateau[stockx1][stocky1]);
								}
							}
						}
					}
				}
			}

			while (coup==2){			/* Cette boucle sert à retourner la deuxieme carte */
				if (SourisCliquee()){
					for (coiny2=marge_x,i=0;i<ligne;i++,coiny2+=150){
						for (coinx2=marge_y,j=0;j<colonne;j++,coinx2+=150){
							y2=i;
							x2=j;
							if ((_X <= (marge_x+y2*ESPACE_CARTE_L)+LONGUEUR_CARTE) && (_X >= marge_x+y2*ESPACE_CARTE_L)){
								if ((_Y <= (marge_y+x2*ESPACE_CARTE_H)+LONGUEUR_CARTE) && (_Y >= marge_y+x2*ESPACE_CARTE_H)){
									CopierZone(5,0,marge_x+y2*ESPACE_CARTE_L,marge_y+x2*ESPACE_CARTE_H,LONGUEUR_CARTE,HAUTEUR_CARTE,marge_x+y2*ESPACE_CARTE_L,marge_y+x2*ESPACE_CARTE_H);									plateau_etat[x2][y2]=1;
									coup++;
									stockagey2=coiny2;
									stockagex2=coinx2;
									stockx2=i;
									stocky2=j;
									printf("%d\n", plateau[stockx2][stocky2]);

										if ((stockx1==stockx2) && (stocky1==stocky2)){  /* Cette boucle empeche l'utilisateur de retourner la premiere carte qui est deja retourné */
											coup=2;
										}
									}
								}
							}
						}
					}
				}
			
			if (coup==3){		
				if (plateau[stockx1][stocky1]!=plateau[stockx2][stocky2] && plateau_etat[stockx1][stocky1]!=2 && plateau_etat[stockx2][stocky2]!=2){
					/*printf("test\n");*/	
					sleep(1);
					CopierZone(6,0,0,0,LONGUEUR_CARTE,HAUTEUR_CARTE,stockagey1,stockagex1);
					CopierZone(6,0,0,0,LONGUEUR_CARTE,HAUTEUR_CARTE,stockagey2,stockagex2);
					plateau_etat[x1][y1]=0;
					plateau_etat[x2][y2]=0;
					coup=1;
				}else if (plateau[stockx1][stocky1]==plateau[stockx2][stocky2]){
					/*printf("%3d %3d %3d %3d\n", stockx1,stocky1,stockx2,stocky2);
					printf("testtest\n");*/
					plateau_etat[x1][y1]=2;
					plateau_etat[x2][y2]=2;
					score++;
					coup=1;
				}			
			}

			if (score==paire){
				sleep(1);
				EffacerEcran(CouleurParNom("black"));
				ChargerImage("./image/bg4.png", 125,150,0,0,1200,1000);
				sleep(2);
				FermerGraphique();
				exit(0);
			}
			flag2=0;
		}
	}
}
