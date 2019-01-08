include $(Rul)
SRC=${wildcard *.c}
OBJ=${patsubst %.c,%.o,$(SRC)}
%.o:%.c
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -c $^ -o $@
all: $(OBJ)
	cp ../include/Array_Operator.h $(Inc)
	mv Array_Operator.o $(Lib)
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -o Test_Array_Operator Test_Array_Operator.c $(Lib)/Array_Operator.o $(Lib)/Log.o
	mv Test_Array_Operator $(Bin)
	rm *.o
clean:
	echo "Array_Operator Clean OK!"
