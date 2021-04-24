#include<20170300.h>

#ifndef NUM_OF_PROCESS
#define NUM_OF_PROCESS 5
#endif

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Add file path following executive file path\n");
        return 0;
    }
    int readfile_fd = open(argv[1], O_RDONLY|O_SYNC);

    int p_counter = 0;
    int fd_arr[NUM_OF_PROCESS][4] = {0};
    for(int i=0; i<NUM_OF_PROCESS; i++)
    {
        pipe(&fd_arr[i][0]), pipe(&fd_arr[i][2]);
    }

    for(int i=1; i<NUM_OF_PROCESS; i++)
    {
        int p_count = fork();
        if(p_count == 0)
        {
            p_counter = i;
            break;
        }
    }

    int send_pipe_fd = (p_counter) % NUM_OF_PROCESS;
    int recv_pipe_fd = (p_counter + NUM_OF_PROCESS - 1) % NUM_OF_PROCESS;
    int first_flag = 0;

    for(int i=0; i<NUM_OF_PROCESS; i++)
    {
        if(i != send_pipe_fd && i!= recv_pipe_fd)
            close(fd_arr[i][0]), close(fd_arr[i][1]);
    }


    while(1)
    {
        if(first_flag == 0 && p_counter == 0)
            first_flag = 1;
        else
        {
            // send the other process that we need to quit
            char sig_buff[1] = {0};
            read(fd_arr[recv_pipe_fd][0], sig_buff, 1);

            if(sig_buff[0] != -1)
            {
                exiting(fd_arr, p_counter, sig_buff[0]);
                break;
            }
        }

        // read character and print it out to the stdout
        char read_buff[100] = {0};
        if(!my_file_read(readfile_fd, read_buff, 100-1))
        {
            printf("%d : %s\n", getpid(), read_buff);
            printf("%d : Read all data\n", getpid());
            exiting(fd_arr, p_counter, p_counter);
            break;
        }
        else
        {
            printf("%d : %s\n", getpid(), read_buff);
            char write_buff[1] = {-1};
            write(fd_arr[send_pipe_fd][1], write_buff, 1);
        }
    }
    if(p_counter == 0)
    {
        int tmp;
        wait(&tmp);
    }
    return 0;
}
