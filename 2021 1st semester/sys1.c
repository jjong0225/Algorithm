#include <stdio.h>
#include <stdlib.h>
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


int read_int(unsigned *input_byte)
{
    int return_d = 0;
    for(int i=0; i<4; i++)
    {
        return_d = return_d | input_byte[i];
        if(i != 3)
            return_d = return_d << 8;
    }

    return return_d;
}

int main ()
{
    FILE *fp = fopen("input.txt", "r");
    unsigned *input_byte = (unsigned *)calloc(2000, sizeof(unsigned));
    int total_size = 0;
    int part_size = 0;
    int break_flag = 1;
    while(break_flag)
    {
        unsigned insert_c = 0;
        for(int i=0; i<8; i++)
        {
            unsigned input_c = 0;
            fscanf(fp, "%c", &input_c);
            if(feof(fp))
            {
                break_flag = 0;
                break;
            }
            if(input_c == '0' || input_c == '1')
            {
                input_c = input_c - '0';
                if(part_size > 1900)
                {
                    realloc(input_byte, 2000);
                    part_size = 0;
                }

                if(i == 0)
                    insert_c = input_c;
                else
                {
                    insert_c = insert_c << 1;
                    insert_c = insert_c + input_c;
                }
            }
        }
        input_byte[total_size++] = insert_c, part_size++;
    }
    printf("%d\n", read_int(input_byte));
}