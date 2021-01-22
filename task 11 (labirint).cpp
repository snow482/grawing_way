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
// # - стены, . - пустота, F - выход, S - старт
/*  5 x 6   transform to->      7 x 8 (-1 on sides)
                        * -1 -1 -1 -1 -1 -1 -1 -1
  # . . # S .           * -1 -1  0  0 -1  1  0 -1
  F # . . . .           * -1  0 -1  0  0  0  0 -1
  . # . # # .           * -1  0 -1  0 -1 -1  0 -1
  . . . . . .           * -1  0  0  0  0  0  0 -1
  # # # # . .           * -1 -1 -1 -1 -1  0  0 -1
                        * -1 -1 -1 -1 -1 -1 -1 -1
*/
// 1) сделать из левой матрицы правую
// 2) пройти все элементы и найти "1". Затем все "0" в радиусе "1" заменить на "2",
// затем все "0" в радиусе "2" заменить на "3" и тд, так до того момента пока не кончатся нули.
// Наибольшее значение и будет выходом (F), вывести его координаты в данной матрице (ответ - (1,0))
// выделить память заранее и перезаписывать значения (скорее всего надо)
//

vector<vector<char>> ReadVector(const string& filePath) {
    std::ifstream input {filePath};
    size_t n, m;
    input >> n;                            // row
    input >> m;                            // colomn
    vector<vector<char>> mtrx(n, vector<char>(m));

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j)
            input >> mtrx[i][j];               // запись этих значений в вектор
    }
    return mtrx;
}

void MatrixPrint(vector<vector<char>>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) { // вектор<векторов>, вывод по колличеству столбцов, а не строк (не квадратная матрица)
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }
}

void MatrixChanging (const char16_t& n, const char16_t& m, vector<vector<char>>& mtrx){

    //TODO - to complete
    int len = mtrx.size();
    for (int i = 0; i < len; ++i) {
        for(int j = 0; j < mtrx[i].size(); ++j){
            if(mtrx[i][j] == '#'){
                mtrx[i][j] = 0x32;
            }
            if(mtrx[i][j] == '.'){
                mtrx[i][j] = 0x30;
            }
            if(mtrx[i][j] == 'S'){
                mtrx[i][j] = 0x31;
            }
            if(mtrx[i][j] == 'F'){
                mtrx[i][j] = 0x30;
            }
        }
    }
}

int main() {


    auto vec = ReadVector("input_11.txt");
    MatrixPrint(vec);
    cout << "\n";
    MatrixChanging(5, 6, vec);
    MatrixPrint(vec);

    return 0;
}


