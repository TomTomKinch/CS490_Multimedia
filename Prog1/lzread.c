//lzread.c
#include <stdio.h>
#include <stdlib.h>

char* dectobin(int dec){
  int cur; 
  int count = 0;
  char* bin = (char*)malloc(9);

  for(int i = 7; i >=0; i--){ //8 bits
    cur = dec >> i;
    if(cur & 1)
      *(bin+count) = 1 + '0';
    else
      *(bin+count) = 0 + '0';
    
    count++;
  }
  //*(bin+count) = '\0';
  return bin;
}

int bintodec(char* bin){
  int dec = 0;
  for(int i = 0; i < 9; i++){
    if(bin[i] == '0')
      dec *= 2;
    else if(bin[i] == '1') 
      dec = dec * 2 + 1; 
  }
  return dec;
}

int main(int argc, char* argv[]){
  
   if(argc != 3){
    printf("Please Call Function with ./lzwrite inputfile outputfile\n");
    return 0;
  };

  FILE *input_file, *output_file;
  long file_size;
  unsigned char * buffer;
  unsigned int padding;

  input_file = fopen(argv[1], "rb");  //Opens File
  
  if(input_file == NULL){   //Error: if file cannot open
    printf("Could Not Open File\n");
    fclose(input_file);
    return 0;
  };

  //Get file size
  fseek(input_file, 0, SEEK_END);
  file_size = ftell(input_file);
  rewind(input_file);
  
  //allocate memory
  buffer = (char*)malloc(sizeof(char)*file_size);
  if(buffer == NULL){
    printf("Buffer Error\n");
    fclose(input_file);
    free(buffer);
    return 0;
  };

  //copy file into buffer
  padding = fread(buffer, 1, file_size, input_file);
  /*
  for(int i = 0; i < file_size; i++){
    printf("%d\n", buffer[i]);
  }
  */

  //Put into longstring
  //Get rid of padding
  char * cur;
  int count = 0;
  int adjustment = 8*file_size - padding + 1; //Adjustment used for longstring size to get rid of padding
  unsigned int longstring[adjustment];
  for(int i = 0; i < adjustment; i+=8){
    cur = dectobin(buffer[count]);  //get binary string (8 bits)
    /*    
    for(int i = 0; i < 8; i++){
      printf("%c", cur[i]);
    }
    printf("\n");
    */  
    count++;
    for(int j = 0; j < 8; j++){
      longstring[i + j] = cur[j]; //combine strings
    }
  }
  
  printf("Combined 9BitString: ");
  for(int i = 0; i < adjustment; i++){
    printf("%c", longstring[i]);
  }
  printf("\n");

  //Turn 9 bits into 8 bits
  unsigned int newlongstring[adjustment - file_size + 1];
  count = 0; //Keeps trak of 8bits
  int val = 0; //Keeps track of position on newlongstring[]
  for(int i = 0; i < adjustment; i++){
    if(count != 0){
      newlongstring[val] = longstring[i];
      val++;
    } 
    if(count == 8)
      count = 0;
    else
      count++;
  }
  printf("Combined 8BitString: ");
  for(int i = 0; i < adjustment - file_size + 1; i++){
    printf("%c", newlongstring[i]);
  }
  printf("\n");

  //OutPut to File
  fclose(input_file);
  output_file = fopen(argv[2], "w+");
  
  if(output_file == NULL){   //Error: if file cannot open
    printf("Could Not Open File\n");
    fclose(output_file);
    return 0;
  };


  //Split into 8 Bits lengths
  char cur_eightbits[8];
  int dec_val = 0;
  count = 0;
  for(int i = 0; i < sizeof(newlongstring)/sizeof(newlongstring[0]); i++){ 
    cur_eightbits[count] = newlongstring[i]; 
    count++;
    if(count == 8){
      //write to file
      dec_val = bintodec(cur_eightbits);
      fputc(dec_val, output_file);
      printf("%d\n", dec_val);
      count = 0;
    }
  }
  

  fclose(output_file);
  free(buffer);

  
  return 0;
}
