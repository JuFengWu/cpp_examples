CC =g++
CFLAGS = -g -std=gnu++11 -Wall 

all:server client clean

server:server.o
	$(CC) -o server server.o
client:client.o
	$(CC) -o client client.o
server.o:server.cpp
	$(CC) $(CFLAGS) -c server.cpp
client.o:client.cpp
	$(CC) $(CFLAGS) -c client.cpp
clean:
	rm server.o client.o
