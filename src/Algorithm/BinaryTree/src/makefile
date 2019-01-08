include $(Rul)
SRC=${wildcard *.c}
OBJ=${patsubst %.c,%.o,$(SRC)}
%.o:%.c
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -c $^ -o $@

All_Lib=\
	$(Lib)/BinaryTree.o \
	$(Lib)/Log.o \
	$(Lib)/List.o \
	$(Lib)/Array_Operator.o \


all:$(OBJ)
	cp ../include/BinaryTree.h $(Inc)
	echo ${OBJ}
	mv BinaryTree.o $(Lib)
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -o Test_BinaryTree Test_BinaryTree.c $(All_Lib)
	mv Test_BinaryTree $(Bin)
	rm *.o
	
clean:
	echo "BinaryTree Clear OK!"
