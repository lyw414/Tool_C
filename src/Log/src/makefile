include $(Rul)
SRC=${wildcard *.c}
OBJ=${patsubst %.c,%.o,$(SRC)}

%.o:%.c
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -c $^ -o $@ 
all: $(OBJ)
	$(CC) $(CFLG) $(INCLUDE) $(DEFINE) -o Test_Log Test_Log.c Log.o -lpthread -I ../include/
	mv Log.o ../../../lib/
	mv Test_Log ../../../bin/
	cp ../include/Log.h ../../../include/
	rm *.o
clean:
	echo "Log Clean OK!"
