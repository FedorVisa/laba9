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
    for (int i = 0; i < m.lines; ++i) {
        for (int j = 0; j < m.lines; ++j) {
            in >> m.data[i][j];
        }
    }
    return in;
}

int determinant:: determinantCount(const determinant& m, size_t lines) {

    for (int i = 0; i < m.lines - 1; i++) { 
        for (int g = 0; g < m.lines; g++) {
            if (g != i) {
                int temp = -(m.data[g][i] / m.data[i][i]);
                for (int j = 0; j < m.lines; j++) {
                    m.data[g][j] = m.data[g][j] + m.data[i][j] * temp;
                }
                
            }
        }
    }
    int det = 1;
    for (int i = 0; i < m.lines; i++) {
        det *= m.data[i][i];
    }

    return det;
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
         
     
         if (m.lines == 1) {
             cout<< m.data[0][0]<< endl;
         }
        
         else if (m.lines == 2) {
             return m.data[0][0] * m.data[1][1] - m.data[0][1] * m.data[1][0];
         }
         else {
  
          /*   int** newMatrix = new int* [m.lines - 1];
             for (int i = 0; i < m.lines - 1; i++) {
                 newMatrix[i] = new int[m.lines - 1];
             }*/

             determinant newMatrix(m.lines-1);

             for (int j = 0; j < m.lines; j++) {
 
                 getMatrixWithoutRowAndCol(m.data, m.lines, 0, j, newMatrix.data);
                 det = det + (degree * m.data[0][j] * logic(newMatrix, m.lines - 1));
                 
                 degree = -degree;
             }

             
             
         }

         return det;
     
 }

