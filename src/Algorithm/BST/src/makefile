include $(Rul)

SRC=${wildcard *.c}
OBJ=${patsubst %.c,%.o,${SRC}}

%.o:%.c 
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -c $^ -o $@

All_Lib=\
	$(Lib)/BST.o \
    $(Lib)/Log.o \
    $(Lib)/List.o


all:$(OBJ)
	cp ../include/BST.h $(Inc)
	echo ${OBJ}
	mv BST.o $(Lib)
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -o Test_BST Test_BST.c $(All_Lib)
	mv Test_BST $(Bin)
	rm *.o
    
clean:
	echo "BinaryTree Clear OK!

