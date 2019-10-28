# 1 - BUT FINAL

but : projet

# 2 - VARIABLES

OFILES =  jeu.o \
          menu.o \
          main.o

CC = gcc

CFLAGS = -g -Wall 

# 3 - DEPENDANCES (REGLES IMPLICITES)

jeu.o :  jeu.h

menu.o : menu.h

main.o : menu.h

# 4 - DEPENDANCES AVEC COMMANDES

projet : $(OFILES)
		$(CC) $(CFLAGS) -o projet $(OFILES) -lgraph

# 5 - NETTOYAGE DES FICHIERS GENERES

clean : 
	-rm -f $(OFILES) projet

# 6 - BUTS FACTICES

.PHONY : but clean

.PHONY:  run

run:
	./projet