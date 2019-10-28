#include <graph.h>
#include "menu.h"

#define LONGUEUR 1200
#define HAUTEUR 1000
#define LONGUEUR_CARTE 100
#define HAUTEUR_CARTE 140

int main(int argc, char * argv[]){

	system("clear");
	InitialiserGraphique();
	CreerFenetre(0,0,LONGUEUR, HAUTEUR);
	menu();
	FermerGraphique();

	return EXIT_SUCCESS;
}