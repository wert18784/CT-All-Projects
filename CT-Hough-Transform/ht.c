#include <stdio.h>
#include <math.h>
#define COL 300//input/binary/line images column number
#define ROW 200//input/binary/line images row number
#define STR_LENGTH 30//file name string length
#define H_COL 1280 //hough image column number
#define H_ROW 768 //hough image row number

int main(int argc, const char * argv[])
{
    unsigned int i, j;		//row and column index
    unsigned int img_inp[ROW][COL];	//input image
    char input_filename[STR_LENGTH];	//input file name string
    FILE *in_file;	                   	//input image file
    FILE *out_file;		//output image file
    char ppm_file_type[STR_LENGTH];	//file type string
    unsigned int ppm_column;              //number of rows in ppm file
    unsigned int ppm_row;                    //number of columns in ppm file
    unsigned int ppm_color; 	//number of colors in ppm file
    unsigned int dmy = 0;                       //garbage can
    unsigned int h[H_ROW][H_COL]; //hough space image
    int x, y; //x and y coordinates of the pixels of the image (int)
    int r; //distance of each pixel from the origin (int)
    unsigned int t; //index for theta
    double PI = 3.141592654; //pi constant
    double amplitude = 2.5;//amplitude constant for sine wave
    double frequency = 4.3;//frequency constant for sine wave
    double phase_x = 0.45, phase_y = 0.2;//phase constants for sine wave
   	
    printf("Input Image File: "); 	//Ask user input file name
    scanf("%s", input_filename);	// Read filename from command line
 
    /** File Open **/
    in_file = fopen(input_filename,"r"); 	//open input image file
    out_file = fopen ("art.ppm","w");	//open output image file
 
    /** Read Input Image Headers **/
    fscanf(in_file, "%s", ppm_file_type);	//read ppm file type
    fscanf(in_file, "%d", &ppm_column);	//read ppm column number
    fscanf(in_file, "%d", &ppm_row);	//read ppm row number
    fscanf(in_file, "%d", &ppm_color);	//read ppm color number
   
    /** Read Pixels from Input Image File **/
    for (i = 0; i < ROW; i++)// for loop for rows
        for (j = 0; j < COL; j++) {// for loop for columns
            fscanf(in_file, "%d", &img_inp[i][j]); //read ppm file pixel data (R)
            fscanf(in_file, "%d", &dmy); //read ppm file pixel data (G) and discard
            fscanf(in_file, "%d", &dmy);//read ppm file pixel data (B) and discard
        }



    //unsigned int i, j; //row and column index
 

    /** Creating Hough Space **/
    for (i = 0; i < ROW; i++)		// for loop for rows
        for (j = 0; j < COL; j++)   	// for loop for columns
        {
            if (img_inp[i][j] == ppm_color)	//if the image pixel is white
            {
                x = j - COL/2;		//calculate x-coordinate with origin at the center
                y = i - ROW/2;		//calculate y-coordinate with origin at the center
                for (t = 0; t < H_COL; t++)	//increment index of theta value (0 to 2 pi)
                {			//calculate r values: r = xcos(t) + ysin(t)
                    //r = (int)((double)x*cos(2.0*PI*(double)t/(double)H_COL) + (double)y*sin(2.0*PI*(double)t/(double)H_COL));
                   r = (int) amplitude*(float)((double)x*cos(2.0*PI*frequency*(double)t/(double)H_COL - phase_x)  + 			                    (double)y*sin(2.0*PI*frequency*(double)t/(double)H_COL - phase_y));
                    if (r< H_ROW/2 && r>= -H_ROW/2)  //if r is within the dimension of the hough space
                        h[r + H_ROW/2][t]++; 	//incrementing pixel value by one
                }   
            }
        }

   
    /** Creating Ouput Image Headers **/
    fprintf(out_file, "%s ", ppm_file_type);//write ppm file type
    fprintf(out_file, "%d ", ppm_column); //write ppm column number
    fprintf(out_file, "%d ", ppm_row); //write ppm row number
    fprintf(out_file, "%d ", ppm_color);//write ppm color

     /** Write Pixels to Output Image File **/
    for (i = 0; i < H_ROW; i++)
        for (j = 0; j < H_COL; j++)
        {
            fprintf(out_file, "%d ", (int)((float) h[i][j]*(1.0 + (float) i/50.0)));	//write ppm pixel data (R)
            fprintf(out_file, "%d ", h[i][j]*(H_COL - j)/40);                              	//write ppm pixel data (G)
            fprintf(out_file, "%d ", h[i][j]*(H_ROW - i)/50);                              	//write ppm pixel data (B)
        }

    /** File Close **/
    fclose(in_file);
    fclose(out_file);
    return 0;
}
