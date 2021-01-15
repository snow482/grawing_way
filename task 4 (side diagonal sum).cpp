#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

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

void MatrixPrint(vector<vector<int>> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size(); ++j) {
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }
}

int SideDiagonalSum (const vector<vector<int>> vec) {
    int sum_value = 0;

    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size(); ++j) {
            /*if(i+j == vec.size()-1)*/     // v1
            if(i == vec.size()-1-j) {       // v2
                sum_value += vec[i][j];
            }
        }
    }

    return sum_value;
}

int main(){

    auto vec = ReadVector("input.txt");
    MatrixPrint(vec);
    cout << "\n" << SideDiagonalSum(vec);

    return 0;
}
