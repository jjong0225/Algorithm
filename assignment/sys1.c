#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

unsigned btol_4byte(unsigned *input_byte)
{
    unsigned return_d = 0;
    for(int i=0; i<4; i++)
    {
        return_d = return_d | input_byte[i];
        if(i != 3)
            return_d = return_d << 8;
    }
    return return_d;
}

unsigned long long int btol_8byte(unsigned *input_byte)
{
    unsigned long long int return_d = 0;
    for(int i=0; i<8; i++)
    {
        return_d = return_d | input_byte[i];
        if(i != 7)
            return_d = return_d << 8;
    }
    return return_d;
}

void read_signed_char_data(unsigned *input_byte, int n)
{
    printf("------Signed_Char------\n");
    for(int i=0; i<n; i++)
    {
        char tmp_c = 0;
        tmp_c = tmp_c | btol_1byte(input_byte + i);
        printf("%d\t", tmp_c);
    }
}

void read_ASCII_codes_data(unsigned *input_byte, int n)
{
    printf("------ASCII_codes------\n");
    for(int i=0; i<n; i++)
    {
        char tmp_c = 0;
        tmp_c = tmp_c | btol_1byte(input_byte + i);
        if(tmp_c >32 && tmp_c < 127)
            printf("%c\t", tmp_c);
        else
            printf(".\t", tmp_c);
    }
}

void read_unsigned_char_data(unsigned *input_byte, int n)
{
    printf("------Unsigned_Char------\n");
    for(int i=0; i<n; i++)
    {
        unsigned char tmp_c = btol_1byte(input_byte + i);
        printf("%d\t", tmp_c);
    }
}

void read_signed_int_data(unsigned *input_byte, int n)
{
    printf("------Signed_int------\n");
    for(int i=0; i<n/4; i++)
    {
        int ouptut_int = 0;
        ouptut_int = ouptut_int | btol_4byte(&input_byte[i*4]);
        printf("%d\t", ouptut_int);
    }
}

void read_unsigned_int_data(unsigned *input_byte, int n)
{
    printf("------Unsigned_int------\n");
    for(int i=0; i<n/4; i++)
    {
        unsigned int ouptut_int = btol_4byte(&input_byte[i*4]);
        printf("%u\t", ouptut_int);
    }
}

void read_signed_float_data(unsigned *input_byte, int n)
{
    printf("------Signed_float------\n");
    for(int i=0; i<n/4; i++)
    {
        unsigned int ouptut_int = btol_4byte(&input_byte[i*4]);
        float tmp_float = 0;
        memcpy(&tmp_float, &ouptut_int, 4);
        printf("%f\t", tmp_float);
    }
}

void read_signed_double_data(unsigned *input_byte, int n)
{
    printf("------Signed_double------\n");
    for(int i=0; i<n/8; i++)
    {
        unsigned long long int ouptut_lld = btol_8byte(&input_byte[i*8]);
        double output_lf = 0;
        memcpy(&output_lf, &ouptut_lld, 8);
        printf("%lf\t", output_lf);
    }
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
    read_signed_char_data(input_byte,total_size);
    printf("\n");
    read_ASCII_codes_data(input_byte,total_size);
    printf("\n");
    read_unsigned_char_data(input_byte,total_size);
    printf("\n");
    read_signed_int_data(input_byte,total_size);
    printf("\n");
    read_unsigned_int_data(input_byte,total_size);
    printf("\n");
    read_signed_float_data(input_byte,total_size);
    printf("\n");
    read_signed_double_data(input_byte,total_size);
    printf("\n");
}