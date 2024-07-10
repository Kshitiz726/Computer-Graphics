#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <vector>
#include <cmath>
using namespace std;

class Matrix {
private:
    int row;
    int column;
    vector<vector<float> > data;

public:
    Matrix(int r, int c) : row(r), column(c), data(r, vector<float>(c, 0)) {}

    void setValue(int r, int c, float value) {
        if (r >= 0 && r < row && c >= 0 && c < column) {
            data[r][c] = value;
        } else {
            cout << "Index out of bounds" << endl;
        }
    }

    int getValue(int r, int c) const {
        if (r >= 0 && r < row && c >= 0 && c < column) {
            return data[r][c];
        } else {
            cout << "Out of index" << endl;
            return -1;
        }
    }

    Matrix operator*(const Matrix& other) const {
        if (column != other.row) {
            cout << "Error: Matrix dimensions do not allow multiplication." << endl;
            return Matrix(0, 0);
        }

        Matrix result(row, other.column);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < other.column; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < column; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
   void print() const {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

Matrix shape(3, 3);

void display() {
    line(shape.getValue(0, 0), shape.getValue(1, 0), shape.getValue(0, 1), shape.getValue(1, 1));
    line(shape.getValue(0, 0), shape.getValue(1, 0), shape.getValue(0, 2), shape.getValue(1, 2));
    line(shape.getValue(0, 2), shape.getValue(1, 2), shape.getValue(0, 1), shape.getValue(1, 1));
}

int main() {
    int options, dx, dy;
    initwindow(1000, 800, "Lab-5");

    // Right Angled Triangle
    line(100, 200, 300, 400);
    line(100, 200, 101, 401);
    line(101, 401, 300, 400);

    shape.setValue(0, 0, 100);
    shape.setValue(0, 1, 300);
    shape.setValue(0, 2, 101);
    shape.setValue(1, 0, 200);
    shape.setValue(1, 1, 400);
    shape.setValue(1, 2, 401);
    shape.setValue(2, 0, 1);
    shape.setValue(2, 1, 1);
    shape.setValue(2, 2, 1);

    cout << "What to do with the shape formed with given points?\n";
    cout << "1. Translation\n";
    cout << "2. Rotation\n";
    cout << "3. Scaling\n";
    cout << "4. Reflection\n";
    cout << "5. Shearing\n";
    cout << "6. Exit\n";
    cout << "Composite Matrix of the figure:\n";
    shape.print();
    cout << "Enter choice: ";
    cin >> options;

    switch (options) {
        case 1: {
            cout << "Enter translation distances dx and dy: ";
            cin >> dx >> dy;

            Matrix translationMatrix(3, 3);
            translationMatrix.setValue(0, 0, 1);
            translationMatrix.setValue(0, 1, 0);
            translationMatrix.setValue(0, 2, dx);
            translationMatrix.setValue(1, 0, 0);
            translationMatrix.setValue(1, 1, 1);
            translationMatrix.setValue(1, 2, dy);
            translationMatrix.setValue(2, 0, 0);
            translationMatrix.setValue(2, 1, 0);
            translationMatrix.setValue(2, 2, 1);
            cout << "Translation Matrix: \n";
            translationMatrix.print();
            shape = translationMatrix * shape;
            cout << "Translated shape composite Matrix: \n";
            shape.print();
            display();
            break;
        }

        case 2: {
            cout << "Enter the angle of rotation in degrees: ";
            int theta;
            cin >> theta;
            float radians = theta * M_PI / 180.0; 

            Matrix rotationMatrix(3, 3);
            rotationMatrix.setValue(0, 0, cos(radians));
            rotationMatrix.setValue(0, 1, -sin(radians));
            rotationMatrix.setValue(0, 2, 0);
            rotationMatrix.setValue(1, 0, sin(radians));
            rotationMatrix.setValue(1, 1, cos(radians));
            rotationMatrix.setValue(1, 2, 0);
            rotationMatrix.setValue(2, 0, 0);
            rotationMatrix.setValue(2, 1, 0);
            rotationMatrix.setValue(2, 2, 1);
            cout << "Rotation Matrix with given angle of Rotation: \n";
            rotationMatrix.print();
            shape = rotationMatrix * shape;
            cout << "Rotated shape composite matrix: \n";
            shape.print();
            display();
            break;
        }

        case 3: {
            cout << "Enter the scaling you want in x and y: ";
            float sx , sy;
            cin >> sx >> sy;
            
            Matrix scalingMatrix(3, 3);
            scalingMatrix.setValue(0, 0, sx);
            scalingMatrix.setValue(0, 1, 0);
            scalingMatrix.setValue(0, 2, 0);
            scalingMatrix.setValue(1, 0, 0);
            scalingMatrix.setValue(1, 1, sy);
            scalingMatrix.setValue(1, 2, 0);
            scalingMatrix.setValue(2, 0, 0);
            scalingMatrix.setValue(2, 1, 0);
            scalingMatrix.setValue(2, 2, 1);
            cout << "Scaling Matrix: \n";
            scalingMatrix.print();
            shape = scalingMatrix * shape;
            cout << "Scaled shape composite Matrix: \n";
            shape.print();
            display();
            break;
        }

        case 4: {
            cout << "Reflection in x axis\n";
            Matrix reflectionMatrix(3, 3);
            reflectionMatrix.setValue(0, 0, 1);
            reflectionMatrix.setValue(0, 1, 0);
            reflectionMatrix.setValue(0, 2, 0);
            reflectionMatrix.setValue(1, 0, 0);
            reflectionMatrix.setValue(1, 1, -1);
            reflectionMatrix.setValue(1, 2, 0);
            reflectionMatrix.setValue(2, 0, 0);
            reflectionMatrix.setValue(2, 1, 0);
            reflectionMatrix.setValue(2, 2, 1);
            cout << "Reflection matrix: \n";
            reflectionMatrix.print();
            shape = reflectionMatrix * shape;
            cout << "Reflected shape composite Matrix: \n";
            shape.print();
            display();
            break;
        }

        case 5: {
            cout << "Enter the shearing you want in x and y: ";
            float shx , shy;
            cin >> shx >> shy;
            
            Matrix shearingMatrix(3, 3);
            shearingMatrix.setValue(0, 0, 1);
            shearingMatrix.setValue(0, 1, shx);
            shearingMatrix.setValue(0, 2, 0);
            shearingMatrix.setValue(1, 0, shy);
            shearingMatrix.setValue(1, 1, 1);
            shearingMatrix.setValue(1, 2, 0);
            shearingMatrix.setValue(2, 0, 0);
            shearingMatrix.setValue(2, 1, 0);
            shearingMatrix.setValue(2, 2, 1);
            cout << "Shearing matrix: \n";
            shearingMatrix.print();
            shape = shearingMatrix * shape;
            cout << "Sheared shape composite matrix: \n";
            shape.print();
            display();
            break;
        }

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid option. Exiting..." << endl;
            break;
    }

    getch();
    closegraph();

    return 0;
}

