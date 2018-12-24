include $(Rul)
SRC=${wildcard *.c}
OBJ=${patsubst %.c,%.o,$(SRC)}

%.o:%.c
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) $(Lib) -c $^ -o $@

all:$(OBJ)
	cp ../include/Stack.h $(Inc)
	mv Stack.o $(Lib)
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -o Test_Stack Test_Stack.c $(Lib)/Log.o $(Lib)/FixedLengthList.o $(Lib)/Stack.o 
	mv Test_Stack $(Bin)
	rm *.o
clear:
	echo "clear OK!"
