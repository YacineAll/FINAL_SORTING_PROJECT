GCC_FLAGS= -std=c99 -lm -ggdb -O3

SRC=entree_sortie.c  Graphe.c  Grille.c  LCircuit.c  ListeDC.c  main_Graphe.c  Solution.c

OBJ=$(SRC:.c=.o)


-include .depends
all:game

game:$(OBJ)
	gcc $(GCC_FLAGS) -o $@ $^
%.o:%.c
	gcc $(GCC_FLAGS) -c $< -o $@  
depend:
	gcc -MM $(SRC) > .depends
clean:
	-rm -f game
	-rm -f *~
	-rm -f $(OBJ)
	-rm -f game
	-rm -f *.sol
