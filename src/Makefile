CFLAGS= -std=c99

SRC=avl.c Cerculaire.c Grille.c LDC.c menu.c naif.c Solution.c

OBJ=$(SRC:.c=.o)

-include .depends

all: depend main
	@-make $@ -C ./graphe_general/
	@-make $@ -C ./SortingProject-daniel_graf/
main: $(OBJ)
	gcc $(CFLAGS) $^ -o $@

%.o: %.c
	gcc $(CFLAGS) -c $<

depend:
	gcc -MM $(SRC) $(CFLAGS) > .depends

clean :
	-rm -f main *.o $(OBJ) .depends
	-rm -f *.sol 
	-rm -f *~
	@-make $@ -C ../graphe_general/
	@-make $@ -C ../SortingProject-daniel_graf/
