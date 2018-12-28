include $(Rul)
SRC=${wildcard *.c}
OBJ=${patsubst %.c,%.o,$(SRC)}

%.o:%.c
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) $(Lib) -c $^ -o $@

all:$(OBJ)
	cp ../include/Queue.h $(Inc)
	mv Queue.o $(Lib)
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -o Test_Queue Test_Queue.c $(Lib)/Log.o $(Lib)/FixedLengthList.o $(Lib)/Queue.o 
	mv Test_Queue $(Bin)
	rm *.o
clear:
	echo "clear OK!"
