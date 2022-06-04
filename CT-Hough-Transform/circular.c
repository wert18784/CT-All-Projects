#define
H_COL 800
//hough image column number

#define
H_ROW 800
//hough image row number

int xx, yy;
//x and y coordiates of the pixels of the circular image (int)

/** Creating Hough Space **/

for (i = 0; i < ROW; i++)
// for loop for rows

for (j = 0; j < COL; j++)
// for loop for columns

{

if (img_inp[i][j] == ppm_color)
//if the image pixel is white

{

x = j - COL/2;
//calculate x-coordinate with origin at the center

y = i - ROW/2;
//calculate y-coordinate with origin at the center

for (t = 0; t < H_COL; t++)
//increment index of theta value (0 to 2 pi)

{
//calculate r values: r = xcos(t) + ysin(t)

//r = (int)((double)x*cos(2.0*PI*(double)t/(double)H_COL) + (double)y*sin(2.0*PI*(double)t/(double)H_COL));

r = (int) amplitude*(float)((double)x*cos(2.0*PI*frequency*(double)t/(double)H_COL - phase_x) +
(double)y*sin(2.0*PI*frequency*(double)t/(double)H_COL - phase_y));

/* Creating Circular Hough Space */

xx = r * cos(2.0*PI*(double)t/(double)H_COL - phase_x);

yy = r * sin(2.0*PI*(double)t/(double)H_ROW - phase_y);

if (xx >= -H_COL/2 && xx < H_COL/2 && yy >= -H_ROW/2 && yy < H_ROW/2)

h[xx+H_COL/2][yy+H_ROW/2] = h[xx+H_COL/2][yy+H_ROW/2] + 1;

}

}

}