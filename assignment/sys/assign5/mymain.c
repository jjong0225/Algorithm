#include "mystdio.h"

int main(){
   const char *filename[2] = { "input2", "output2" };
   FILE *infile = fopen(filename[0], "r");
   FILE *outfile = fopen(filename[1], "w");
   char buffer;
   
   while(1){
      buffer = fgetc(infile);
      fputc(buffer, outfile);
      fflush(outfile);
      if(feof(infile))
         break;
   }

   fclose(infile);
   fclose(outfile);

   return 0;
}