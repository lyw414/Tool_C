include $(Rul)
SRC=${wildcard *.c}
OBJ=${patsubst %.c,%.o,$(SRC)}
%.o:%.c
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) $(Lib) -c $^ -o $@

all:$(OBJ)
	cp ../include/KMP.h $(Inc)
	mv KMP.o $(Lib)
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -o Test_KMP Test_KMP.c $(Lib)/KMP.o $(Lib)/Log.o 
	mv Test_KMP $(Bin)
	rm *.o
clean:
	echo "KMP Clean OK!"

