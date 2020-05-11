//Thomas Kinch, Michael Kelly
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#define pi 3.1415926535897932

//Compile with gcc -o myDCT myDCT.c -lm

void zigzag(double dct_matrix[8][8], FILE* output_filename){
    fprintf(output_filename, "\n");
    fprintf(output_filename, "%5.0lf ", dct_matrix[0][0]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[1][0]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[0][1]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[0][2]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[1][1]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[2][0]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[3][0]);
    fprintf(output_filename, "%5.0lf \n", dct_matrix[2][1]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[1][2]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[0][3]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[0][4]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[1][3]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[2][2]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[3][1]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[4][0]);
    fprintf(output_filename, "%5.0lf \n", dct_matrix[5][0]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[4][1]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[3][2]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[2][3]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[1][4]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[0][5]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[0][6]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[1][5]);
    fprintf(output_filename, "%5.0lf \n", dct_matrix[2][4]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[3][3]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[4][2]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[5][1]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[6][0]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[7][0]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[6][1]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[5][2]);
    fprintf(output_filename, "%5.0lf \n", dct_matrix[4][3]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[3][4]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[2][5]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[1][6]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[0][7]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[1][7]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[2][6]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[3][5]);
    fprintf(output_filename, "%5.0lf \n", dct_matrix[4][4]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[5][3]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[6][2]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[7][1]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[7][2]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[6][3]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[5][4]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[4][5]);
    fprintf(output_filename, "%5.0lf \n", dct_matrix[3][6]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[2][7]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[3][7]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[4][6]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[5][5]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[6][4]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[7][3]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[7][4]);
    fprintf(output_filename, "%5.0lf \n", dct_matrix[6][5]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[5][6]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[4][7]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[5][7]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[6][6]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[7][5]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[7][6]);
    fprintf(output_filename, "%5.0lf ", dct_matrix[6][7]);
    fprintf(output_filename, "%5.0lf \n", dct_matrix[7][7]);
}

void quantization(double quant_matrix[8][8], double dct_matrix[8][8], double qscale){
    printf("QUANTIZED\n");
    //Quantization
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dct_matrix[j][i] = round( dct_matrix[j][i] / (quant_matrix[j][i]*qscale));
            if(dct_matrix[j][i] > 128 && dct_matrix[j][i] <= 200){ //Bounds Check for values
                dct_matrix[j][i] = 128;
            }
            else if(dct_matrix[j][i] >= -200 && dct_matrix[j][i] < -127){ //Bounds Check for values
                dct_matrix[j][i] = -127;
            }
            dct_matrix[j][i] += 127;
            printf("%.0lf\t", dct_matrix[j][i]);
        }
        printf("\n");
    }
    printf("---------------------------------------------\n");
}

void dct(double eight_arr[8][8], double dct_arr[8][8]){  

    double cu, cv, curr_val, sum; 
    
    //DCT Formula
    for (int i = 0; i < 8; i++) { 
        for (int j = 0; j < 8; j++) { 
            if (i == 0) 
                cu = 1 / sqrt(8); 
            else
                cu = sqrt(2) / sqrt(8); 
            if (j == 0) 
                cv = 1 / sqrt(8); 
            else
                cv = sqrt(2) / sqrt(8); 
  
            sum = 0; 
            for (int k = 0; k < 8; k++) { 
                for (int l = 0; l < 8; l++) { 
                    curr_val = eight_arr[k][l] *  
                        cos((2 * k + 1) * i * pi / (16)) * 
                        cos((2 * l + 1) * j * pi / (16));
                    sum = sum + curr_val; 
                } 
            } 
            dct_arr[i][j] = cu * cv * sum;
            if(signbit(dct_arr[i][j]))  //Checks/fixes negative zeros
                dct_arr[i][j] *= -1;
        } 
    } 
    //Prints DCT array
    printf("DCT\n");
    for (int i = 0; i < 8; i++) { 
        for (int j = 0; j < 8; j++) { 
            printf("%.0lf\t", dct_arr[j][i]); 
        } 
        printf("\n"); 
    }
     
}

void split_eight_by_eight(int start_x, int start_y, unsigned int** MB_arr, double eight_arr[8][8]){
    int x = start_x;
    int y = start_y;
    //Splits our 16x16 array into 8x8
    printf("EIGHT x EIGHT\n");
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            eight_arr[j][i] = MB_arr[x][y];
            x++;
            printf("%.0lf\t", eight_arr[j][i]);
        }
        y++;
        x = start_x;
        printf("\n");
    }
}

unsigned int** create_MB(unsigned char* arr_values){
    
    //Allocate Memory for 16x16 2D array
    unsigned int* values = calloc(16*16, sizeof(unsigned int));
    unsigned int** MB_arr = malloc(16*sizeof(unsigned int*));
    for(int i = 0; i < 16; i++){
        MB_arr[i] = values + i*16;
    };

    //Fills MB array with values
    int count = 0;
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            MB_arr[j][i] = (uintptr_t)arr_values[count];
            count++;
            printf("%5d", MB_arr[j][i]);
        }
        printf("\n");
    }
    return MB_arr;
};

void compress(unsigned char* arr_values, int x_dim, int y_dim, double quant_matrix[8][8], double qscale, FILE *output_file){

    unsigned int* values = calloc(16*16, sizeof(unsigned int));
    unsigned int** MB_arr = malloc(16*sizeof(unsigned int*));
    int count = 0;
    char temp_MB[256];
    double eight_arr[8][8];
    double dct_arr[8][8];
    int arr_x[4] = {0, 8, 0, 8};
    int arr_y[4] = {0, 0, 8, 8};

    //Loop through picture
    for(int i = 0; i < (x_dim * y_dim); i += x_dim*16){      //Loop through each row
        for(int n = 0; n < y_dim; n+=16){                     //Loop through each column
            for(int j = 0; j < 256*(x_dim/16); j += x_dim){    //Loop through each row of 16x16 MB
                for(int k = 0; k < 16; k++){                    //Loop through each column of 16x16 MB
                    temp_MB[count] = arr_values[i + j + k + n];
                    count++;
                }
            }
            count = 0;
            //Begin Compressing
            MB_arr = create_MB(temp_MB);

            //Break into 8x8 arrays
            for(int i = 0; i < 4; i++){
                //Split into 8x8 array
                split_eight_by_eight(arr_x[i], arr_y[i], MB_arr, eight_arr);
                //Send 8x8 arr to DCT
                dct(eight_arr, dct_arr);
                //Quantization
                quantization(quant_matrix, dct_arr, qscale);
                //ZigZag / send to output file
                zigzag(dct_arr, output_file);
            }
        }
    }
    
};

int read_quantfile(char* quantfilename, double quant_matrix[8][8]){
    FILE *quant_file;
    int file_size; 
    char * linebuffer;
    quant_file = fopen(quantfilename, "r");  //Opens File
 
    if(quant_file == NULL){   //Error: if file cannot open
      printf("Could Not Open File\n");
      fclose(quant_file);
      return 0;
    };
 
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

    //Get quantization matrix from quantfile
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

int main(int argc, char* argv[]) {

    FILE *input_file, *output_file;
    long file_size;
    char * linebuffer;
    unsigned int padding;

    //Get qscale
    double qscale = atoi(argv[3]);
 
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
    linebuffer = (char*)malloc(sizeof(char)*file_size);
    if(linebuffer == NULL){
      printf("Buffer Error\n");
      fclose(input_file);
      free(linebuffer);
      return 0;
    };

    //Read file
    size_t buffsize = 0;
    getline(&linebuffer, &buffsize, input_file);
    getline(&linebuffer, &buffsize, input_file);
    
    //Define Dimensions of Picture
    int x_dim, y_dim;
    int byte_count = 2 + 4 + 3;
    char* token;
    token  = strtok(linebuffer, " ");
    byte_count += strlen(token);
    x_dim = atoi(token);
    printf("%d\n", x_dim);
    token = strtok(NULL, " ");
    y_dim = atoi(token);
    byte_count += strlen(token);
    printf("%d\n", y_dim);

    //Get Array Values
    char ignore[byte_count];
    unsigned char arr_values[x_dim * y_dim + 1];
    fgets(ignore, sizeof(ignore), input_file); //Skip first 3 lines
    fgets(arr_values, x_dim * y_dim + 1, input_file); //Get array values

    //Read QuantFile
    double quant_matrix[8][8];
    read_quantfile(argv[2], quant_matrix);

    output_file = fopen(argv[4], "w");  //Opens File
 
    if(output_file == NULL){   //Error: if file cannot open
      printf("Could Not Open File\n");
      fclose(output_file);
      return 0;
    };
    
    //Fill in header for output file
    fprintf(output_file, "Filename: %s\n", argv[1]);
    fprintf(output_file, "qscale: %lf\n", qscale);
    fprintf(output_file, "dimensions: %d x %d\n", x_dim, y_dim);

    //Compress Picture
    compress(arr_values, x_dim, y_dim, quant_matrix, qscale, output_file);
    printf("\n");

    fclose(input_file);
    free(linebuffer);
    fclose(output_file);
    return 0;

}