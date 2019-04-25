SRC=${wildcard *.c}
OBJ=${patsubst %.c,%.o,$(SRC)}
%.o:%.c
	gcc -Wall -g -c $^ -o $@ -I ../include/
all:$(OBJ)
	gcc -o Test_Heap $(OBJ)
	rm *.o
	cp ../include/* ../../../../include/
	mkdir -p ../../../../bin/
	mv Test_Heap ../../../../bin/
