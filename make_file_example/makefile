
CC = g++
INSTDIR = /usr/local/bin
INCLUDE = ./include
CFLAGS = -g -std=gnu++11 -Wall 
LIBS += -framework CoreFoundation


GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include
INCLUDE_DIR = ./include
G++_FLAGS = -c -Wall -I $(GOOGLE_TEST_INCLUDE) -I $(INCLUDE_DIR)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread

all:main.out test.out clean

main.out: main.o tm_move_api.o tm_test.o
	$(CC) -o main.out main.o tm_move_api.o tm_test.o

main.o: src/main.cpp include/tm_move_api.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c src/main.cpp
tm_move_api.o: src/tm_move_api.cpp include/tm_move_api.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c src/tm_move_api.cpp
tm_test.o: src/tm_test.cpp include/tm_test.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c src/tm_test.cpp

test.out: main_test.o string_compare.o
	$(CC) -o test.out main_test.o string_compare.o $(LD_FLAGS)

main_test.o: test/main_test.cpp 
	$(CC) $(G++_FLAGS) test/main_test.cpp 

string_compare.o: test/string_compare.cpp
	$(CC) $(G++_FLAGS) test/string_compare.cpp 


clean:
	rm -f main.o api.o tm_test.o tm_move_api.o main_test.o string_compare.o

.PHONY: all
