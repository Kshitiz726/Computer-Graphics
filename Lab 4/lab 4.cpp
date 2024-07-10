#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
class midpoint_algorithm {
private:
int a, b, xc, yc;
public:
midpoint_algorithm(int a, int b, int xc, int yc) {
this->a = a;
this->b = b;
this->xc = xc;

this->yc = yc;
}
void generate() {
int x0 = 0;
int y0 = b;
float p;
// Region 1
p = pow(b, 2) - pow(a, 2) * b + 0.25 * pow(a, 2);
int x = 0, y = b;
while (2 * pow(b, 2) * x < 2 * pow(a, 2) * y) {
if (p < 0) {
x++;
p += 2 * pow(b, 2) * x + pow(b, 2);
} else {
x++;
y--;
p += 2 * pow(b, 2) * x - 2 * pow(a, 2) * y + pow(b, 2);
}
putpixel(x+xc, y+yc, WHITE);
putpixel(-x+xc, y+yc, WHITE);
putpixel(x+xc, -y+yc, WHITE);
putpixel(-x+xc, -y+yc, WHITE);
}
// Region 2
p = pow(b, 2) * pow((x + 0.5), 2) + pow(a, 2) * pow((y - 1), 2) - pow(a, 2) * pow(b, 2);
while (y > 0) {
if (p > 0) {

y--;
p += -2 * pow(a, 2) * y + pow(a, 2);
} else {
x++;
y--;
p += 2 * pow(b, 2) * x - 2 * pow(a, 2) * y + pow(a, 2);
}
putpixel(x+xc, y+yc, WHITE);
putpixel(-x+xc, y+yc, WHITE);
putpixel(x+xc, -y+yc, WHITE);
putpixel(-x+xc, -y+yc, WHITE);
}
}
};
int main() {
int gd = DETECT, gm;
initwindow(800, 600, "Ellipse Drawing");
outtextxy(170,50, "Kshitiz Lab-4");
midpoint_algorithm ellipse(90, 60, 220,70);
ellipse.generate();
getch();
closegraph();
return 0;
}
