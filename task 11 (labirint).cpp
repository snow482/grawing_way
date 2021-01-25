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

vector<vector<int>> ReadVector(const string& filePath) {
    std::ifstream input {filePath};
    size_t n, m;
    input >> n >> m;                            // row colomn
    vector<vector<int>> mtrx(n, vector<int>(m, 0));



    char symbol;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            input >> symbol;               // запись этих значений в вектор
            switch(symbol) {
                case '.':
                    mtrx[i][j] = 0;
                    break;
                case '#':
                    mtrx[i][j] = -1;
                    break;
                case 'S':
                    mtrx[i][j] = 1;
                    break;
                case 'F':
                    mtrx[i][j] = 0;
                    break;
                default:
                    cout << "error" << endl;
                    break;
            }
        }
    }
    return mtrx;
}

void MatrixPrint(vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) { // вектор<векторов>, вывод по колличеству столбцов, а не строк (не квадратная матрица)
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }
}


int main() {

    auto vec = ReadVector("input_11.txt");
    
    MatrixPrint(vec);
    cout << "\n";

    return 0;
}


