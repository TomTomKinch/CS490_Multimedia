//lzwrite.c
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

int main(int argc, char* argv[]) {

  if(argc != 3){
    printf("Please Call Function with ./lzwrite inputfile outputfile\n");
    return 0;
  };

  FILE *input_file, *output_file;
  long file_size;
  char * buffer;
  unsigned int padding, binary, val;

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
  //printf("%d", padding);
  //printf("\n");
  printf("Input: %s", buffer);

  //Convert 8 bit to 9 bit 
  //Concatinate into one long binary string
  char * cur;
  int count = 0;
  unsigned int longstring[9*file_size + padding];
  for(int i = 0; i < 9*file_size; i+=9){
    longstring[i] = '0';        //add 9th bit
    cur = dectobin(buffer[count]);  //get binary string (8 bits)
    /*
    for(int i = 0; i < 8; i++){
      printf("Binary: %c", cur[i]);
    }
    printf("\n");
    */
    count++;
    for(int j = 1; j < 9; j++){
      longstring[i + j] = cur[j-1]; //combine strings
    }
  }
  
  printf("Combined 9BitString: ");
  for(int i = 0; i < 9*file_size; i++){
    printf("%c", longstring[i]);
  }
  printf("\n");

  //Pad the length
  for(int i = 9*file_size; i < 9*file_size + padding + 1; i++){
    longstring[i] = '0';
  }
  
  printf("Padded 9BitString:   ");
  for(int i = 0; i < 9*file_size+padding; i++){
  
    printf("%c", longstring[i]);
  }
  printf("\n"); 

  //Open outputfile
  fclose(input_file);
  output_file = fopen(argv[2], "w+b");  //Opens File
  
  if(output_file == NULL){   //Error: if file cannot open
    printf("Could Not Open File\n");
    fclose(output_file);
    return 0;
  };


  //Split into 8 Bits lengths
  char cur_eightbits[8];
  int dec_val = 0;
  count = 0;
  for(int i = 0; i < sizeof(longstring)/sizeof(longstring[0]); i++){ 
    cur_eightbits[count] = longstring[i]; 
    count++;
    if(count == 8){
      //write to file
      fputc(strtol(cur_eightbits, NULL, 2), output_file);
      count = 0;
    }
  }
  

  fclose(output_file);
  free(buffer);

return 0;
}
