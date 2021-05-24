//#include<stdio.h>
#include "mystdio.h"
#define testnum 100

int main ()
{
    FILE *my_file_ptr = fopen("./input.txt", "r");
    FILE *my_file_ptr2 = fopen("./output.txt", "a");
    int input_buf[testnum] = {0};
    int tmp_val;
    int now_idx;


    // fread 테스트
    // fread(input_buf, sizeof(input_buf[0]), testnum, my_file_ptr);
    // write(1, input_buf, 1*sizeof(input_buf[0]));


    // feof 테스트
    // fseek(my_file_ptr, 0, SEEK_END);
    // char output[3] = {'1', '0'};
    // if(feof(my_file_ptr) == -1)
    //     write(1, &output[0], 1); // eof
    // else
    //     write(1, &output[1], 1); // !eof


    // fwrite 테스트
    // fwrite(input_buf, sizeof(input_buf[0]), testnum, my_file_ptr2);


    // fgetc 테스트
    // tmp_val = 0;
    // now_idx = 0;
    // while(tmp_val != EOF && now_idx < testnum)
    // {
    //     tmp_val = fgetc(my_file_ptr);
    //     input_buf[now_idx++] = tmp_val;
    // }
    // write(1, input_buf, testnum);


    // fputc 테스트
    // tmp_val = 0;
    // now_idx = 0;
    // while(tmp_val > -1 && now_idx < testnum)
    // {
    //     fputc(input_buf[now_idx++], my_file_ptr2);
    // }

    // fgetc fputc 동시 테스트
    int c;
    while ((c = fgetc(my_file_ptr)) != EOF) fputc(c, my_file_ptr2);
   fclose(my_file_ptr2);

    return 0;
}