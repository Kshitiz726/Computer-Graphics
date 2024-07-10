#include <iostream>
#include <conio.h>
#include <graphics.h>
class bresenhams_algorithm{
	private:
		int x, y, dx, dy;
	public:
		void draw_line(int x1, int y1, int x2, int y2)
		{
			x = x1 ;
			y = y1;
			dx = x2 - x1;
			dy = y2 - y1;
			int p = 2 * dy - dx;
			while( x <= x2)
			{
				putpixel(x,y, WHITE);
				if ( p < 0)
				{
					p = p + 2 * dy;
					
				}
				else{
					p = p + (2 * dy) - (2 * dx);
					y++;
				}
				x++;
					
			}
		}
		
};
using namespace std;
int main()
{
	int gd = DETECT, gm;
	initwindow(800, 600, "Bresenham's Line Drawing Algorithm");
	outtextxy(330,10, "Kshitiz Lab2");
	bresenhams_algorithm linedrawing;
	int x1, y1, x2, y2;
	cout << "\"Kshitiz Lab2\"\n";
	cout << "Enter the coordinates of the first point (x1, y1) :";
	cin >> x1>> y1;
	cout << "Enter the coordinates of the second point (x2, y2) :";
	cin >> x2>>y2;
	linedrawing.draw_line (x1, y1, x2, y2);
	getch();
	closegraph();
	return 0;
}
