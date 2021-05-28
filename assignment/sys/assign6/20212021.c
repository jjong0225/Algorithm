#include "20212021.h"
#include <stdio.h>

// An example of a semphore for the mutual exclusion

semaphore_t mutex;
FILE *fp = NULL;
char buffer[3][BUFSIZ] = {0};

void writer(void)
{
    printf("Thread %d is writing 3 line", get_thread_id);
    for(int i=0; i<3; i++)
    {
        printf("%s", buffer[i]);
    }
}

void reader(void)
{
    fscanf(fp, "%s", buffer[get_thread_id-1]);
    printf("Thread %d is reading a line", get_thread_id);
}

int main(int argc, char *argv[])
{
	// example of initializing a semaphore
    fp = fopen(argv[1], "r");
    mutex = sem_create(1);

    // your code

    // create threads
    create_thread(reader);
    create_thread(reader);
    create_thread(reader);
    create_thread(writer);
    
    // Let's run
    run();
    
    // stupid while loop
    while (1) {
    	sleep(1);
    }
}   




