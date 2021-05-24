#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char btod_1byte(unsigned char *input_byte);
unsigned int btod_4byte(unsigned char *input_byte);
unsigned long long int btod_8byte(unsigned char *input_byte);
void read_signed_char_data(unsigned char *input_byte, int n);
void read_ASCII_codes_data(unsigned char *input_byte, int n);
void read_unsigned_char_data(unsigned char *input_byte, int n);
void read_signed_int_data(unsigned char *input_byte, int n);
void read_unsigned_int_data(unsigned char *input_byte, int n);
void read_signed_float_data(unsigned char *input_byte, int n);
void read_signed_double_data(unsigned char *input_byte, int n);
