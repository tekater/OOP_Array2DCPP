#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Array2D {
    int* arr;
    int rows, columns;
    int index(int i, int j)
    {
        return i * columns + j;
    }
public:
    Array2D(int rows, int columns) : arr{ new int[rows * columns] },
        rows{ rows }, columns{ columns } {};
    ~Array2D()
    {
        delete[]arr;
    }
    void randomize()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                arr[index(i, j)] = rand() % 10;
            }
        }
    }

    void delator(int pos) {
        columns--;
        int* narr = new int[(rows) * columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                    narr[index(i, j)] = arr[index(i, j + (j>=pos)+i)];
            }
        }
        delete[] arr;
        arr = narr;
    }
    void dobaver(int pos) {
        
        int* narr = new int[rows * (columns + 1)] {};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns+1; j++) {
                    narr[index(i, j + (j >= pos) + i)] = arr[index(i, j)];
            }
        }
        
        delete[] arr;
        arr = narr;
        columns++;
    }

    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << arr[index(i, j)] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    setlocale(0, "");
    Array2D a{ 5,10 };
    a.randomize();
    a.print();
    a.dobaver(2);
    a.print();
}
