#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

// fill a matrix like showed below (function that needs to repeat couple of times)
/* 8x8 - 4, 6x6 - 3, 4x4 - 2, 2x2 - 1
 * 4 4 4 4 4 4 4 4
 * 4 3 3 3 3 3 3 4
 * 4 3 2 2 2 2 3 4
 * 4 3 2 1 1 2 3 4
 * 4 3 2 1 1 2 3 4
 * 4 3 2 2 2 2 3 4
 * 4 3 3 3 3 3 3 4
 * 4 4 4 4 4 4 4 4
*/

// выделить память заранее и перезаписывать значения
// int - 4 байта, 4 х (8х8) = 256 байт

vector<vector<int>> ReadVector(const string& filePath) {
    std::ifstream input {filePath};
    size_t n, m;
    input >> n;                            // row
    input >> m;                            // colomn
    vector<vector<int>> mtrx(n, vector<int>(m));

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j)
            input >> mtrx[i][j];               // запись этих значений в вектор
    }
    return mtrx;
}

void MatrixPrint(vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size(); ++j) {
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }
}

void Function_1 (const int32_t& n, const int32_t& m, vector<vector<int>>& vec,
                 int fillValue, int otstup) {

    if(otstup == 0) {
        for (int i = 0; i < m; ++i) {
            vec[n-5-otstup][i] = fillValue; //first
            vec[n-4-otstup][i] = fillValue; //last
        }
        for (int i = 0; i < n; ++i) {
            vec[i][m-5-otstup] = fillValue; //left
            vec[i][m-4-otstup] = fillValue; //right
        }
    }if (otstup == 1) {
        for (int i = 0; i < m; ++i) {
            vec[n-5-otstup][i] = fillValue; //first
            vec[n-2-otstup][i] = fillValue; //last
        }
        for (int i = 0; i < n; ++i) {
            vec[i][m-5-otstup] = fillValue; //left
            vec[i][m-2-otstup] = fillValue; //right
        }
    }if (otstup == 2) {
        for (int i = 0; i < m; ++i) {
            vec[n-5-otstup][i] = fillValue; //first
            vec[n-otstup][i] = fillValue;   //last
        }
        for (int i = 0; i < n; ++i) {
            vec[i][m-5-otstup] = fillValue; //left
            vec[i][m-otstup] = fillValue;   //right
        }
    }if (otstup == 3) {
        for (int i = 0; i < m; ++i) {
            vec[n-otstup-5][i] = fillValue; //first
            vec[n-otstup+2][i] = fillValue; //last
        }
        for (int i = 0; i < n; ++i) {
            vec[i][m-otstup-5] = fillValue; //left
            vec[i][m-otstup+2] = fillValue; //right
        }

    }
}

int main() {

    auto vec = ReadVector("input_4.1.txt");
    MatrixPrint(vec);

    Function_1(8,8,vec, 1, 0);
    Function_1(8,8,vec, 2, 1);
    Function_1(8,8,vec, 3, 2);
    Function_1(8,8,vec, 4, 3);
    cout << "\n";
    MatrixPrint(vec);

    return 0;
}


