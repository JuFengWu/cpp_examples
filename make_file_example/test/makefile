CC = g++

GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include
INCLUDE_DIR = ../include
G++_FLAGS = -c -Wall -I $(GOOGLE_TEST_INCLUDE) -I $(INCLUDE_DIR)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread

all: test.out  clean

test.out: main_test.o string_compare.o
	$(CC) -o test.out main_test.o string_compare.o $(LD_FLAGS)

main_test.o: main_test.cpp 
	$(CC) $(G++_FLAGS) main_test.cpp 

string_compare.o: string_compare.cpp
	$(CC) $(G++_FLAGS) string_compare.cpp 

clean:
	rm -f main_test.o string_compare.o
