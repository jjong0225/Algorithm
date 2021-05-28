#include "20170300.h"
#include <stdio.h>

// An example of a semphore for the mutual exclusion

semaphore_t mutex;
FILE *fp = NULL;
char buffer[3][BUFSIZ] = {0};

void writer(void)
{
    while(1)
    {
        P(&mutex);
        printf("Thread %d is writing 3 line\n", get_thread_id());
        for(int i=0; i<3; i++)
        {
            printf("%s\n", buffer[i]);
        }
        if(feof(fp))
            break;
        V(&mutex);
    }
}

void reader(void)
{
    while(1)
    {
        P(&mutex);
        if(!feof(fp))
        {
            fscanf(fp, "%s", buffer[get_thread_id()-1]);
            printf("Thread %d is reading a line\n", get_thread_id());
        }
        V(&mutex);
    }
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Add file path following executive file path\n");
        return 0;
    }
    fp = fopen(argv[1], "r");
    mutex = sem_create(1);

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




