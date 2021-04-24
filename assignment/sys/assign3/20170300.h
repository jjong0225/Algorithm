#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include <fcntl.h>

#define NUM_OF_PROCESS 5
int my_file_read(int readfile_fd, char *read_buff, int max_size);
int exiting(int fd_arr[NUM_OF_PROCESS][4], int p_counter, int finish_idx);

int my_file_read(int readfile_fd, char *read_buff, int max_size)
{
    for(int now_idx = 0; now_idx < max_size; now_idx++)
    {
        char tmp_input[1] = {0};
        int tmp_result = 0;
        tmp_result = read(readfile_fd, tmp_input, 1);

        if(tmp_result)
        {
            if(tmp_input[0] == '\n')
                return now_idx;
            else
                read_buff[now_idx] = tmp_input[0];
        }
        else
            return 0;
    }
    return 0;
}

int exiting(int fd_arr[NUM_OF_PROCESS][4], int p_counter, int finish_idx)
{
    int send_pipe_fd = (p_counter) % NUM_OF_PROCESS;
    int recv_pipe_fd = (p_counter + NUM_OF_PROCESS - 1) % NUM_OF_PROCESS;

    char tmp_buff[2] = {finish_idx};
    write(fd_arr[send_pipe_fd][1], tmp_buff, 2);

    if(p_counter < finish_idx)
    {
        read(fd_arr[send_pipe_fd][2], tmp_buff, 2);
    }
    else
    {
        read(fd_arr[recv_pipe_fd][0], tmp_buff, 2);
        if(p_counter != NUM_OF_PROCESS-1)
        {
            write(fd_arr[send_pipe_fd][1], tmp_buff, 2);
            read(fd_arr[send_pipe_fd][2], tmp_buff, 2);
        }
    }
    printf("%d : I'm exiting...\n", getpid());
    write(fd_arr[recv_pipe_fd][3], tmp_buff, 2);
    return 1;
}
