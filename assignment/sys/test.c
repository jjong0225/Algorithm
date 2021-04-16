#include<stdio.h>
#include<unistd.h>

int main()
{
    int counter = 0;
    for(int i=1; i<=6; i++)
    {
        int pid = fork();
        if(pid == 0)
        {
            counter = i;
            break;
        }
    }
    printf("%d : %d번째 프로세스", getpid(), counter);
}
