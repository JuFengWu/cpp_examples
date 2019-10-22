CC =g++
CFLAGS = -g -std=c++14 -Wall 

all:unique_ptr.out shared_ptr.out clean

unique_ptr.out:unique_ptr.o
	$(CC) -o unique_ptr.out unique_ptr.o
unique_ptr.o:unique_ptr.cpp
	$(CC) $(CFLAGS) -c unique_ptr.cpp

shared_ptr.out:shared_ptr.o
	$(CC) -o shared_ptr.out shared_ptr.o
shared_ptr.o:shared_ptr.cpp
	$(CC) $(CFLAGS) -c shared_ptr.cpp

clean:
	rm unique_ptr.o shared_ptr.o
