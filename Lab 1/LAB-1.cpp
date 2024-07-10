// Including preprocessor directives.
#include <graphics.h>
#include <conio.h>
void DDA(int x_initial , int y_initial , int x_final, int y_final){
	int dx = x_final - x_initial;
    int dy = y_final - y_initial;
	float slope = (dy)/(dx);
	delay(100);
	while(x_initial != x_final && y_initial != y_final)
	{
		
	if(slope < 1)
	{
		x_initial = x_initial + 1; 
		y_initial = y_initial + slope;
	}
	else if (slope > 1)
	{
		y_initial = y_initial + 1; 
		x_initial = x_initial + (1/slope);
	}
	else if (slope == 1)
	{
		x_initial = x_initial + 1; 
		y_initial = y_initial + 1;
	}
	putpixel(x_initial, y_initial, RED);	
	}
}
//Declaring Main function
int main()
{
    int gd = DETECT, gm; 
  
    // Initialize graphics function 
    initgraph(&gd, &gm, "");
	initwindow(1100, 900 , "Graphics Lab");
    // Draw 'K'
    DDA(50, 50, 51, 250);
    DDA(50, 150, 100, 50);
    DDA(50, 150, 101, 250);
    
    // Draw 'S'
    DDA(170, 50, 270, 51);
    DDA(170, 150, 270, 151);
    DDA(170, 250, 270, 251);
    DDA(170, 50, 171, 150);
    DDA(270, 150, 271, 250);
    
    // Draw 'H'
    DDA(290, 50, 291, 250);
    DDA(390, 50, 391, 250);
    DDA(290, 150, 390, 151);
    
    // Draw 'I'
    DDA(410, 50, 510, 51);
    DDA(460, 50, 461, 250);
    DDA(410, 250, 510, 251);
    
    // Draw 'T'
    DDA(530, 50, 630, 51);
    DDA(580, 50, 581, 250);

    // Draw 'I' again
    DDA(650, 50, 750, 51);
    DDA(700, 50, 701, 250);
    DDA(650, 250, 750, 251);

// Draw 'J'
DDA(770, 50, 970, 51);  // Top horizontal line
DDA(870, 50, 871, 250); // Vertical line
DDA(770, 250, 870, 251); // Bottom horizontal line
    
    //concluding the program
	getch(); 
    closegraph();
	return 0;
}


