#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>
#include <queue>

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
// Имеются координаты точки начала, есть координаты точки выхода, найти путь выхода из лабиринта,
// не используя двойной цикл пробега по матрице, а найдя 1, двигаться уже от нее глядя по сторонам
// (надо использовать std::queue, записывать туда координаты значений по сторонам и затем менять их,
// таким образом будет набор значений: 1 2 2 2 2 3 3 3 4 4 4 5 5 5 6 6 7 8 8 8 9 9 10)
// Двигаться до тех пор пока очередь не будет пуста или не будет найден искомый финишный элемент.

std::vector<std::vector<int>> ReadVector(const std::string& filePath) {
    std::ifstream input {filePath};
    size_t n, m;
    input >> n >> m;                            // row colomn
    std::vector<std::vector<int>> mtrx(n+2, std::vector<int>(m+2, 0));

    // frame filling
    int fillVallue = -1;
    for(int i = 0; i < m+2; ++i){
        mtrx[0][i] = fillVallue; // first
        mtrx[n+1][i] = fillVallue; // last
    }
    for (int i = 0; i < n+2; ++i) {
        mtrx[i][0] = fillVallue; // left
        mtrx[i][m+1] = fillVallue; // right
    }

    // find the desired symbols and changing
    char symbol;
    for(int i = 1; i < n+1; ++i) {
        for(int j = 1; j < m+1; ++j) {
            input >> symbol;
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
                    std::cout << "error" << std::endl;
                    break;
            }
        }
    }
    return mtrx;
}


void FindingRightWay(const int& nForFind,
                     const int& mForFind,
                     std::vector<std::vector<int>>& mtrx){
    std::queue<std::pair<int,int>> queueList;

    for(int i = 0; i < mtrx.size(); ++i) {
        for(int j = 0; j < mtrx[i].size(); ++j) {
            if(mtrx[i][j] == 1){
                queueList.push(std::pair(i, j));
            }
        }
    }

    static std::array<int, 4> si = {0, 0, 1, -1};
    static std::array<int, 4> sj = {-1, 1, 0, 0};

    while (mtrx[nForFind][mForFind] == 0){
        if(!queueList.empty()) {
            auto [i, j] = queueList.front();
            queueList.pop();

            for(int ind = 0; ind < 4; ++ind) {
                auto ii = i + si[ind];
                auto jj = j + sj[ind];
                if( mtrx[ii][jj] == 0) {
                   mtrx[ii][jj] = mtrx[i][j]+1;
                   queueList.emplace(ii, jj);
                }
            }
        }
        else {
            break;
        }
    }
}

void MatrixPrint(std::vector<std::vector<int>>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        // вектор<векторов>, вывод по кол-ву столбцов, а не строк
        // (не квадратная матрица) n < m
        for (int j = 0; j < vec[i].size(); ++j) {
            std::cout << vec[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {

    auto vec = ReadVector("input_11.txt");
    MatrixPrint(vec);
    std::cout << "\n";
    FindingRightWay(2, 1, vec);
    MatrixPrint(vec);

    return 0;
}


