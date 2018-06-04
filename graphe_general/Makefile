GCC_FLAGS=-Wall -g -std=c99 -lm -ggdb -O3 -pipe -fstack-protector -fstack-protector-all

SRC=Graphe.c Grille.c Lcircuit.c ListeDC.c generale_graphe.c Solution.c
OBJ=$(SRC:.c=.o)

all:game

game:$(OBJ)
	gcc $(GCC_FLAGS) -o $@ $^
%.o:%.c
	gcc $(GCC_FLAGS) -c $< -o $@  
clean:
	-rm -f *~
	-rm -f $(OBJ)
	-rm -f game
	-rm -f *.sol
run:
	./game $(ARGS)
