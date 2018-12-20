include $(Rul)
SRC=${wildcard *.c}
OBJ=${patsubst %.c,%.o,$(SRC)}

%.o:%.c
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) $(Lib) -c $^ -o $@
all:$(OBJ)
	cp ../include/FixedLengthList.h $(Inc)
	mv FixedLengthList.o $(Lib)
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -o Test_FList Test_FList.c $(Lib)/Log.o $(Lib)/FixedLengthList.o 
	#mv Test_FList $(Bin)
	rm *.o
clean:
	echo "Log Clean OK!"
