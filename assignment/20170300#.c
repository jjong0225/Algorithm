#include "20170300#.h"

unsigned char btod_1byte(unsigned char *input_byte) // just return 1byte from unsigned char array
{
    unsigned char return_d = 0;
    return_d = return_d | input_byte[0];
    return return_d;
}

unsigned int btod_4byte(unsigned char *input_byte) // convert 4 unsigned char to unsigned int data and return it
{
    unsigned int return_d = 0;
    for(int i=0; i<4; i++)
    {
        return_d = return_d | input_byte[i];
        if(i != 3)
            return_d = return_d << 8;
    }
    return return_d;
}

unsigned long long int btod_8byte(unsigned char *input_byte) // convert 8 unsigned char to unsigned long long data int and return it
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

void read_signed_char_data(unsigned char *input_byte, int n) // using btod_1byte, read memory as signed_char format
{
    printf("------Signed_Char------\n");
    for(int i=0; i<n; i++)
    {
        char tmp_c = 0;
        tmp_c = tmp_c | btod_1byte(input_byte + i);
        printf("%d\t", tmp_c);
    }
    printf("\n");
}

void read_ASCII_codes_data(unsigned char *input_byte, int n) // using btod_1byte, read memory as signed_char format
{
    printf("------ASCII_codes------\n");
    for(int i=0; i<n; i++)
    {
        char tmp_c = 0;
        tmp_c = tmp_c | btod_1byte(input_byte + i);
        if(tmp_c >= 0 && tmp_c <= 127)
            printf("%c\t", tmp_c);
        else
            printf(".\t", tmp_c);
    }
    printf("\n");
}

void read_unsigned_char_data(unsigned char *input_byte, int n)  // using btod_1byte, read memory as ASCII format
{
    printf("------Unsigned_Char------\n");
    for(int i=0; i<n; i++)
    {
        unsigned char tmp_c = btod_1byte(input_byte + i);
        printf("%d\t", tmp_c);
    }
    printf("\n");
}

void read_signed_int_data(unsigned char *input_byte, int n) // using btod_4byte, read memory as signed_int format
{
    printf("------Signed_int------\n");
    for(int i=0; i<n/4; i++)
    {
        int ouptut_int = 0;
        ouptut_int = ouptut_int | btod_4byte(&input_byte[i*4]);
        printf("%d\t", ouptut_int);
    }
    printf("\n");
}

void read_unsigned_int_data(unsigned char *input_byte, int n) // using btod_4byte, read memory as unsigned_int format
{
    printf("------Unsigned_int------\n");
    for(int i=0; i<n/4; i++)
    {
        unsigned int ouptut_int = btod_4byte(&input_byte[i*4]);
        printf("%u\t", ouptut_int);
    }
    printf("\n");
}

void read_signed_float_data(unsigned char *input_byte, int n) // using btod_4byte, read memory as signed_float format
{
    printf("------Signed_float------\n");
    for(int i=0; i<n/4; i++)
    {
        unsigned int ouptut_int = btod_4byte(&input_byte[i*4]);
        float tmp_float = 0;
        memcpy(&tmp_float, &ouptut_int, 4); // using memcpy, copy all bits in output_int to tmp_float
        printf("%.4f\t", tmp_float);
    }
    printf("\n");
}

void read_signed_double_data(unsigned char *input_byte, int n) // using btod_8byte, read memory as signed_double format
{
    printf("------Signed_double------\n");
    for(int i=0; i<n/8; i++)
    {
        unsigned long long int ouptut_lld = btod_8byte(&input_byte[i*8]);
        double output_lf = 0;
        memcpy(&output_lf, &ouptut_lld, 8); // using memcpy, copy all bits in output_int to output_lf
        printf("%.4lf\t", output_lf);
    }
    printf("\n");
}

int main ()
{
    unsigned char *input_byte = (unsigned char  *)calloc(110000000, sizeof(unsigned char ));
    int total_size = 0;
    int break_flag = 1;

    // part1. file read
    FILE *fp = fopen("input", "r");
    while(break_flag)
    {
        unsigned char insert_c = 0;
        for(int i=0; i<8;) // get 8 binary numbers from the file and store those data as a unsigned_char type(1byte) to memory
        {
            unsigned char input_c = 0;
            fscanf(fp, "%c", &input_c);
            if(feof(fp)) // if eof, break
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

    // part2. memory read
    read_signed_char_data(input_byte,total_size);
    read_ASCII_codes_data(input_byte,total_size);
    read_unsigned_char_data(input_byte,total_size);
    read_signed_int_data(input_byte,total_size);
    read_unsigned_int_data(input_byte,total_size);
    read_signed_float_data(input_byte,total_size);
    read_signed_double_data(input_byte,total_size);
}