CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=myBank.o
FLAGS=-Wall -g


all: myBanks myBankd mains maind 	
mains: $(OBJECTS_MAIN) libmyBank.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a
maind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmyBank.so
myBankd: libmyBank.so
libmyBank.so: $(OBJECTS_LIB)
	$(CC) -shared -o libmyBank.so $(OBJECTS_LIB) 
libmyBank.a: $(OBJECTS_LIB)
	$(CC) -shared -o libmyBank.a $(OBJECTS_LIB) 
myBanks: $(OBJECTS_LIB)
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB)	
main.o: main.c myBank.h 
	$(CC) $(FLAGS) -c main.c 
myBank.o: myBank.c myBank.h  
	$(CC) $(FLAGS) -c -fPIC myBank.c  

.PHONY: clean all myBankd myBanks

clean:
	rm -f *.o *.a *.so mains maind
