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


unsigned char btol_1byte(unsigned *input_byte)
{
    unsigned char return_d = 0;
    return_d = return_d | input_byte[0];
    return return_d;
}

int btol_4byte(unsigned *input_byte)
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

void read_integer_data(unsigned *input_byte, int n)
{
    printf("------Integer------\n");
    for(int i=0; i<n/4; i++)
    {
        int ouptut_int = btol_4byte(&input_byte[i*4]);
        printf("%d\n", ouptut_int);
    }
    printf("------Integer------\n");
}

void read_char_data(unsigned *input_byte, int n)
{
    printf("------Char------\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\n", btol_1byte(input_byte + i));
    }
    printf("------Char------\n");    
}

int main ()
{
    FILE *fp = fopen("input", "r");
    unsigned *input_byte = (unsigned *)calloc(200000000, sizeof(unsigned));
    int total_size = 0;
    int break_flag = 1;
    while(break_flag)
    {
        unsigned insert_c = 0;
        for(int i=0; i<8;)
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
                if(i == 0)
                    insert_c = input_c;
                else
                {
                    insert_c = insert_c << 1;
                    insert_c = insert_c + input_c;
                }
                i++;
            }
        }
        input_byte[total_size++] = insert_c;
    }
    total_size--;
    read_integer_data(input_byte,total_size);
    printf("\n");
    read_char_data(input_byte,total_size);
}