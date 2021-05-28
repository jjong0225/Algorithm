#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MyBufferSize 8192
#define EOF -1

typedef struct my_file
{
  int fd;
  int flags; // 파일 모드

  char *read_base;       /* Start of putback+get area. */
  char *read_ptr;        /* Current read pointer       */
  char *read_end;        /* End of get area.           */

  char *write_base;      /* Start of put area.         */
  char *write_ptr;       /* Current put pointer.       */
  char *write_end;       /* End of put area.           */
} FILE;

FILE *filestream_arr[100] = {0};
int num_of_filestream = 0;
int handler_flag = 0;

FILE* fopen(char *fileName, char *openMode);
int fread(void *ptr, int size, int nmemb, FILE *stream);
int fclose(FILE *stream);
int fwrite(const void *ptr, int size, int nmemb, FILE *stream);
int fgetc(FILE *stream);
int fputc(int c, FILE *stream);
int feof(FILE *stream);
int fflush(FILE *stream);
int openMode_to_openFlag(char *openMode);
int fill_readbuffer(FILE *stream);
void termination_handler(void);

FILE* fopen(char *fileName, char *openMode)
{
    FILE* file_stream = (FILE*)calloc(1, sizeof(FILE));
    int open_flag = 0;

    file_stream->read_base = (char *)calloc(MyBufferSize,sizeof(char));
    file_stream->read_end = file_stream->read_base - 1;
    file_stream->read_ptr = file_stream->read_base;

    file_stream->write_base = (char *)calloc(MyBufferSize,sizeof(char));
    file_stream->write_end = file_stream->write_base + MyBufferSize-1;
    file_stream->write_ptr = file_stream->write_base;

    // handling file open mode
    int openFlag = openMode_to_openFlag(openMode);
    file_stream->fd = open(fileName, openFlag, 0777);

    filestream_arr[num_of_filestream++] = file_stream;
    if(handler_flag == 0)
    {
        atexit(termination_handler);
        handler_flag = 1;
    }
    return file_stream;
}

int fclose(FILE *stream)
{
    fflush(stream);
    return close(stream->fd);
}

int fgetc(FILE *stream)
{
    if(stream->read_end < stream->read_ptr)
        if(fill_readbuffer(stream) == 0) return EOF;

    unsigned char output = *(stream->read_ptr);
    (stream->read_ptr)++;
    return output;
}

int fputc(int c, FILE *stream)
{
    if(stream->write_end < stream->write_ptr)
        if(fflush(stream) == EOF) return EOF;
    (*stream->write_ptr) = c;
    (stream->write_ptr)++;
    return c;
}

int fread(void *ptr, int size, int nmemb, FILE *stream)
{
    int num_of_remains = nmemb;
    while(num_of_remains > 0)
    {
        if(stream->read_end < stream->read_ptr)
            if(fill_readbuffer(stream) == 0) break;

        int remain_buff_size = stream->read_end - stream->read_ptr + 1;
        int next_size =  (remain_buff_size < (num_of_remains*size)) ? remain_buff_size : (num_of_remains*size);
        memcpy(ptr + ((nmemb - num_of_remains)*size), stream->read_ptr, next_size);
        stream->read_ptr = stream->read_ptr + next_size;
        num_of_remains -= (next_size / size);
    }
    return nmemb - num_of_remains;
}

int fwrite(const void *ptr, int size, int nmemb, FILE *stream)
{
    int num_of_remains = nmemb;
    while(num_of_remains > 0)
    {
        if(stream->write_end < stream->write_ptr)
            if(fflush(stream) == EOF) break;
        
        int remain_buff_size = stream->write_end - stream->write_ptr + 1;
        int next_size = (remain_buff_size < (num_of_remains * size)) ? remain_buff_size : num_of_remains * size;
        memcpy(stream->write_ptr, ptr + ((nmemb - num_of_remains)*size), next_size);
        stream->write_ptr = stream->write_ptr + next_size;
        num_of_remains -= (next_size / size);
    }
    return nmemb - num_of_remains;
}

int fflush(FILE *stream)
{
    if(stream == NULL)
    {
        for(int i=0; i<num_of_filestream; i++)
        {
            if(filestream_arr[i] != NULL)
                fflush(filestream_arr[i]);
        }
    }
    else
    {
        int write_count = write(stream->fd, stream->write_base, stream->write_ptr - stream->write_base);
        if(write_count <= 0) return EOF;
        memset(stream->write_base, 0, MyBufferSize);
        stream->write_ptr = stream->write_base;
    }
    return 0;
}

int fseek(FILE *stream, int offset, int whence)
{
    if(lseek(stream->fd, offset, whence) >= 0)
    {
        memset(stream->read_base, 0, MyBufferSize);
        stream->read_end = stream->read_base - 1;
        stream->read_ptr = stream->read_base;
        return 0;
    }
    else
        return -1;
}

int feof(FILE *stream)
{
    if(stream->read_end >= stream->read_ptr)
        return 0;
    else
    {
        unsigned char tmp_buffer[2] = {0};
        int read_count = read(stream->fd, tmp_buffer, 1);
        if(read_count == 0)
            return -1;
        else
        {
            lseek(stream->fd, -1, SEEK_CUR);
            return 0;
        }
    }
}

int fill_readbuffer(FILE *stream)
{
    memset(stream->read_base, 0, MyBufferSize);
    int input_size = read(stream->fd, stream->read_base, MyBufferSize);
    if(input_size <= 0) return 0;
    stream->read_ptr = stream->read_base;
    stream->read_end = stream->read_base + input_size - 1;
    return 1;
}

int openMode_to_openFlag(char *openMode)
{
    if(!strcmp(openMode, "r"))
        return O_RDONLY;
    else if(!strcmp(openMode, "r+"))
        return O_RDWR;
    else if(!strcmp(openMode, "w"))
        return  O_CREAT|O_WRONLY|O_TRUNC;
    else if(!strcmp(openMode, "w+"))
        return O_RDWR|O_CREAT|O_TRUNC;
    else if(!strcmp(openMode, "a"))
        return O_WRONLY|O_CREAT|O_APPEND;
    else if(!strcmp(openMode, "a+"))
        return O_RDWR|O_CREAT|O_APPEND;
    else
        return -1;
}

void termination_handler(void)
{
    fflush(NULL);
}