#include "determinant.h"
#include <iostream>
using namespace std;

determinant :: determinant(size_t lines) : lines(lines){
    data = new double* [lines];
    for (int i = 0; i < lines; ++i) {
        data[i] = new double[lines];
    }
}



determinant::determinant(const determinant& m) :
    lines(m.lines) {
    data = new double* [m.lines];
    for (int i = 0; i < m.lines; ++i) {
        data[i] = new double[m.lines];
    }

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < lines; ++j) {
            data[i][j] = m.data[i][j];
        }
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

 ostream &operator<<(ostream& out,  determinant &m) {
    
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