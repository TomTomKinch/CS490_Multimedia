//Thomas Kinch, Michael Kelly
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#define pi 3.1415926535897932

void unzigzag(double eight_arr[8][8], FILE* input_file, char* linebuffer, size_t buffsize){
    char* token;
    getline(&linebuffer, &buffsize, input_file);
    getline(&linebuffer, &buffsize, input_file);
    token = strtok(linebuffer, " ");
    eight_arr[0][0] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[1][0] = atoi(token);
    token = strtok(NULL, " ");
    eight_arr[0][1] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[0][2] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[1][1] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[2][0] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[3][0] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[2][1] = atoi(token);
    token = strtok(NULL, " ");
    getline(&linebuffer, &buffsize, input_file);
    token = strtok(linebuffer, " ");
    eight_arr[1][2] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[0][3] = atoi(token);
    token = strtok(NULL, " ");
    eight_arr[0][4] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[1][3] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[2][2] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[3][1] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[4][0] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[5][0] = atoi(token);
    getline(&linebuffer, &buffsize, input_file);
    token = strtok(linebuffer, " ");
    eight_arr[4][1] = atoi(token); 
    token = strtok(NULL, " ");
    eight_arr[3][2] = atoi(token);
    token = strtok(NULL, " ");
    eight_arr[2][3] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[1][4] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[0][5] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[0][6] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[1][5] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[2][4] = atoi(token);
    getline(&linebuffer, &buffsize, input_file);
    token = strtok(linebuffer, " ");
    eight_arr[3][3] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[4][2] = atoi(token);
    token = strtok(NULL, " ");
    eight_arr[5][1] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[6][0] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[7][0] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[6][1] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[5][2] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[4][3] = atoi(token);
    getline(&linebuffer, &buffsize, input_file);
    token = strtok(linebuffer, " ");
    eight_arr[3][4] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[2][5] = atoi(token);
    token = strtok(NULL, " ");
    eight_arr[1][6] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[0][7] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[1][7] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[2][6] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[3][5] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[4][4] = atoi(token);
    getline(&linebuffer, &buffsize, input_file);
    token = strtok(linebuffer, " ");
    eight_arr[5][3] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[6][2] = atoi(token);
    token = strtok(NULL, " ");
    eight_arr[7][1] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[7][2] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[6][3] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[5][4] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[4][5] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[3][6] = atoi(token);
    getline(&linebuffer, &buffsize, input_file);
    token = strtok(linebuffer, " ");
    eight_arr[2][7] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[3][7] = atoi(token);
    token = strtok(NULL, " ");
    eight_arr[4][6] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[5][5] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[6][4] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[7][3] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[7][4] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[6][5] = atoi(token);
    getline(&linebuffer, &buffsize, input_file);
    token = strtok(linebuffer, " ");
    eight_arr[5][6] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[4][7] = atoi(token);
    token = strtok(NULL, " ");
    eight_arr[5][7] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[6][6] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[7][5] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[7][6] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[6][7] = atoi(token);
    token = strtok(NULL, " "); 
    eight_arr[7][7] = atoi(token);
    
    //Prints Array read from file
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("%.0lf ", eight_arr[i][j]);
        }
        printf("\n");
    } 
}

int read_quantfile(char* quantfilename, double quant_matrix[8][8]){
    FILE *quant_file;
    int file_size; 
    char * linebuffer;
    quant_file = fopen(quantfilename, "r");  //Opens File
 
    if(quant_file == NULL){   //Error: if file cannot open
      printf("Could Not Open File\n");
      fclose(quant_file);
      return 0;
    }

     //Get file size
    fseek(quant_file, 0, SEEK_END);
    file_size = ftell(quant_file);
    rewind(quant_file);

    //allocate memory
    linebuffer = (char*)malloc(sizeof(char)*file_size/8);
    if(linebuffer == NULL){
      printf("Buffer Error\n");
      fclose(quant_file);
      free(linebuffer);
      return 0;
    };

    size_t buffsize = 0;
    char* token;

    //Read quant matrix values from file
    for(int i = 0; i < 8; i++){
        getline(&linebuffer, &buffsize, quant_file);
        token = strtok(linebuffer, " ");
        for(int j = 0; j <  8; j++){
            quant_matrix[j][i] = atoi(token);
            token = strtok(NULL, " ");
        }
    }
    free(linebuffer);
    fclose(quant_file);
}

void unquantization(double eight_arr[8][8], double quant_matrix[8][8], double qscale){
    printf("UNQUANTIZED\n");
    //Inverse Quantization
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            eight_arr[j][i] -= 127;
            eight_arr[j][i] = round( eight_arr[j][i] * (quant_matrix[j][i]*qscale));
            printf("%.0lf\t", eight_arr[j][i]);
        }
        printf("\n");
    }
}

void idct(double eight_arr[8][8], double idct_arr[8][8]){
    
    double cu, cv, curr_val, sum; 
  
    //Inverse DCT formula
    for (int i = 0; i < 8; i++) { 
        for (int j = 0; j < 8; j++) {   
            sum = 0; 
            for (int k = 0; k < 8; k++) { 
                for (int l = 0; l < 8; l++) { 
                    if (k == 0) 
                        cu = 1 / sqrt(2); 
                    else
                        cu = 1; 
                    if (l == 0) 
                        cv = 1 / sqrt(2); 
                    else
                        cv = 1; 
                    curr_val = eight_arr[k][l] *  
                        cos((2 * i + 1) * k * pi / (16)) * 
                        cos((2 * j + 1) * l * pi / (16));
                    sum = sum + (curr_val * cu * cv); 
                } 
            } 
            idct_arr[i][j] = sum/4;
        } 
    } 
  
    //Prints IDCT array
    printf("IDCT\n");
    for (int i = 0; i < 8; i++) { 
        for (int j = 0; j < 8; j++) { 
            printf("%.0lf\t", idct_arr[j][i]); 
        } 
        printf("\n"); 
    }
    printf("---------------------------------------\n");
}

void output_func(double idct[8][8], FILE* output_file){
    //Outputs to outpput file
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            fprintf(output_file, "%5.0lf ", idct[j][i]);
        }
        fprintf(output_file, "\n");
    }
    fprintf(output_file, "\n");
}

void decompress(char* linebuffer, size_t buffsize, double eight_arr[8][8], double qscale, int x_dim, int y_dim, double quant_matrix[8][8], FILE* input_file, FILE* output_file){
    //Decompression
    double idct_arr[8][8];
    for(int i = 0; i < (x_dim*y_dim)/64; i++){
        unzigzag(eight_arr, input_file, linebuffer, buffsize);
        unquantization(eight_arr, quant_matrix, qscale);
        idct(eight_arr, idct_arr);
        output_func(idct_arr, output_file);
    }

}

int main(int argc, char* argv[]){

    FILE *input_file, *output_file;
    long file_size;
    char* linebuffer;

    input_file = fopen(argv[1], "r");  //Opens File
 
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
    linebuffer = (char*)malloc(sizeof(char)*file_size);
    if(linebuffer == NULL){
      printf("Buffer Error\n");
      fclose(input_file);
      free(linebuffer);
      return 0;
    };

    //Read File
    double eight_arr[8][8];
    double qscale; 
    int x_dim, y_dim;
    char* token;
    int byte_count = 0;
    size_t buffsize = 0;

    //Get Header Information
    getline(&linebuffer, &buffsize, input_file); //Skip line 1
    getline(&linebuffer, &buffsize, input_file);
    token = strtok(linebuffer, " "); //Skip qscale txt
    token = strtok(NULL, " "); //Grab qscale value
    qscale = atoi(token);
    printf("qscale: %lf\n", qscale);
    getline(&linebuffer, &buffsize, input_file); 
    token = strtok(linebuffer, " ");
    token = strtok(NULL, " ");
    x_dim = atoi(token);
    printf("x_dim: %d\n", x_dim);
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    y_dim = atoi(token);
    printf("y_dim: %d\n", y_dim);

    //Read quantfile
    double quant_matrix[8][8];
    read_quantfile(argv[2], quant_matrix);
    output_file = fopen(argv[3], "w");
    if(output_file == NULL){   //Error: if file cannot open
      printf("Could Not Open File\n");
      fclose(output_file);
      return 0;
    };
    
    decompress(linebuffer, buffsize, eight_arr, qscale, x_dim, y_dim, quant_matrix, input_file, output_file);
    
    fclose(input_file);
    free(linebuffer);
    fclose(output_file);
    return 0;
}