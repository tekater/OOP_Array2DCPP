#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Array2D {
    int* arr;
    int rows;
    int columns;
    int index(int i, int j) {
        return (i)*columns + j;
    }
public:
    Array2D(int r, int col) {
        rows = r;
        columns = col;
        //arr = new int*[rows];
        /*arr = new int* [rows * columns];
        

        for (int i = 0; i < rows; i++) {
            arr[i] = new int[columns];
        }*/
    }
    void random() {
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++) {
                arr[index(i,j)] = rand() % 10;
            }
        }
    }
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    ~Array2D() {
        /*for (int i = 0; i < rows; i++) {
                delete[] arr[i];
        }*/
        delete[] arr;
    }
};

int main() {

    setlocale(0, "");
    srand(time(NULL));

    Array2D ad{ 5,10 };
    ad.random();
    ad.print();
}
