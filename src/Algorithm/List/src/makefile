include $(Rul)
SRC=${wildcard *.c}
OBJ=${patsubst %.c,%.o,$(SRC)}
%.o:%.c
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -c $^ -o $@
all: $(OBJ)
	cp ../include/List.h $(Inc)
	mv List.o $(Lib)
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -o Test_List Test_List.c $(Lib)/List.o $(Lib)/Log.o
	mv Test_List $(Bin)
	rm *.o
clean:
	echo "Log Clean OK!"
