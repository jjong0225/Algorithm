#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include <fcntl.h>

#define NUM_OF_PROCESS 5

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Add file path following executive file path\n");
        return 0;
    }
    int readfile_fd = open(argv[1], O_RDONLY|O_SYNC);


    int p_counter = 0;
    int fd_arr[NUM_OF_PROCESS][2] = {0};
    for(int i=0; i<NUM_OF_PROCESS; i++)
    {
        if(pipe(fd_arr[i]) == -1)
        {
            printf("something went wrong");
            return 0;
        }
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

    for(int i=0; i<NUM_OF_PROCESS; i++)
    {
        if(i != send_pipe_fd && i!= recv_pipe_fd)
            close(fd_arr[i][0]), close(fd_arr[i][1]);
    }

    while(1)
    {
        // read signal part
        char sig_buff[1] = {0};
        read(fd_arr[recv_pipe_fd][0], sig_buff, 1);
        int next_sig = 0;

        if(sig_buff[0] == -1)
        {
            if(p_counter == NUM_OF_PROCESS -1)
            {
                char sig_buff_2[1] = {-2};
                write(fd_arr[recv_pipe_fd][1], sig_buff_2, 1);
                break;
            }
            else
            {
                // send the other process that we need to quit
                char tmp_buff_4[1] = {-1};
                write(fd_arr[send_pipe_fd][1], tmp_buff_4, 1);

                // listening
                char tmp_buff[1] = {0};
                read(fd_arr[send_pipe_fd][0], tmp_buff, 1);
                if(tmp_buff[0] == -2)
                    break;
            }
        }
        else
        {
            // read character and print it out to the stdout
            char read_buff[1] = {0};
            read(readfile_fd, read_buff, 1);

            if(read_buff[0] == EOF)
                next_sig = -1;
            else
            {
                printf("%d[%d번째 프로세스] : %c\n", getpid(), p_counter, read_buff[0]);
                next_sig = 1;
            }
            char write_buff[1] = {next_sig};
            write(fd_arr[send_pipe_fd][1], write_buff, 1);
        }
    }

    char tmp_buff_3[1] = {-2};
    write(fd_arr[recv_pipe_fd][1], tmp_buff_3, 1);

    int status;
    wait(&status);

    return 0;
}
