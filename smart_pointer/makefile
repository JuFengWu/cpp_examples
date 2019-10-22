CC =g++
CFLAGS = -g -std=c++14 -Wall 

all:unique_ptr clean

unique_ptr:unique_ptr.o
	$(CC) -o unique_ptr unique_ptr.o
unique_ptr.o:unique_ptr.cpp
	$(CC) $(CFLAGS) -c unique_ptr.cpp
clean:
	rm unique_ptr.o
