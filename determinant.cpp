#include "determinant.h"
#include <iostream>
using namespace std;

determinant :: determinant(size_t lines) : lines(lines){
    data = new int* [lines];
    for (int i = 0; i < lines; ++i) {
        data[i] = new int[lines];
    }
}

determinant :: ~determinant() {

    if (data)
        for (int i = 0; i < lines; ++i) {
            delete[]data[i];
        }
    delete[]data;
    data = nullptr;
}

determinant::determinant(const determinant& m) :
    lines(m.lines) {
    data = new int* [m.lines];
    for (int i = 0; i < m.lines; ++i) {
        data[i] = new int[m.lines];
    }

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < lines; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}



ostream& operator<<(ostream& out, const determinant& m) {

    for (int i = 0; i < m.lines; ++i) {
        for (int j = 0; j < m.lines; ++j) {
            out << m.data[i][j] << ' ';
        }
        out << '\n';
    }

    return out;
}

istream& operator>>(istream& in, const determinant& m) {
    if (std::cin.fail())throw"input error";
    for (int i = 0; i < m.lines; ++i) {
        for (int j = 0; j < m.lines; ++j) {
            in >> m.data[i][j];
        }
    }
    
    return in;
}

determinant:: determinant(determinant&&m) :
    lines(m.lines) {
    for (int i = 0; i < m.lines; ++i) {
        for (int j = 0; j < m.lines; ++j) {
            m.data[i][j] = data[i][j];
        }
    }
    for (int i = 0; i < m.lines; ++i) {
        for (int j = 0; j < m.lines; ++j) {
            m.data[i][j] = NULL;
        }
    }
    m.lines = 0;
}


void getMatrixWithoutRowAndCol(int** matrix, int size, int row, int col, int** newMatrix ) {
    int offsetRow = 0; 
    int offsetCol = 0; 
    for (int i = 0; i < size - 1; i++) {
        
        if (i == row) {
            offsetRow = 1; 
        }

        offsetCol = 0; 
        for (int j = 0; j < size - 1; j++) {
            
            if (j == col) {
                offsetCol = 1; 
            }

            newMatrix[i][j] = matrix[i + offsetRow][j + offsetCol];
        }
    }
}

 int determinant::logic(const determinant& m, size_t lines) {
         int det = 0;
         int degree = 1; 
         
         if (m.lines == 0) { 
             throw "lines must be >0";
             
         }
         if (m.lines == 1) {
             cout<< m.data[0][0]<< endl;
         }
        
         else if (m.lines == 2) {
             return m.data[0][0] * m.data[1][1] - m.data[0][1] * m.data[1][0];
         }
         else {
  
             determinant newMatrix(m.lines-1);

             for (int j = 0; j < m.lines; j++) {
 
                 getMatrixWithoutRowAndCol(m.data, m.lines, 0, j, newMatrix.data);
                 det = det + (degree * m.data[0][j] * logic(newMatrix, m.lines - 1));
                 
                 degree = -degree;
             }
         }

         return det;
     
 }

