#include <stdio.h>

int main(){
   const char *filename[2] = { "input2", "output2" };
   FILE *infile = fopen(filename[0], "r+");
   char buffer;
   
   while(1){
      buffer = fgetc(infile);
      fflush(infile);
      fputc(buffer, infile);
      if(feof(infile))
         break;
   }

   fclose(infile);

   return 0;
}