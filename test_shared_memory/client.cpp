/*
 * shm-client - client program to demonstrate shared memory.
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <cstdlib>

#define SHMSZ     200 // char size

main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678;

   
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");//send error message to stderr
        exit(1);
    }

    
    if ((shm = (char*)shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /*
     * Now read what the server put in the memory.
     */
    for (s = shm; *s != 0; s++)
        putchar(*s);
    putchar('\n');

    /*
     * Finally, change the first character of the 
     * segment to '*', indicating we have read 
     * the segment.
     */
    *shm = '*';

    exit(0);
}
