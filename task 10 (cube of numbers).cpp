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
/* 8x8 - 0, 6x6 - 1, 4x4 - 2, 2x2 - 3
 * 0 0 0 0 0 0 0 0
 * 0 1 1 1 1 1 1 0
 * 0 1 2 2 2 2 1 0
 * 0 1 2 3 3 2 1 0
 * 0 1 2 3 3 2 1 0
 * 0 1 2 2 2 2 1 0
 * 0 1 1 1 1 1 1 0
 * 0 0 0 0 0 0 0 0
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
void VecWrite(const size_t& n, const size_t& m, const vector<int>& vec){
    std::ofstream output {"output_4.1.txt"};
    output << n << endl;
    output << m << endl;
    for(const auto& it : vec)
        output << it << " ";

    output.close();
}
void MatrixPrintHorizontal(vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size(); ++j) {
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }
}
void VectorPrint(const vector<int>& vec) {
    for(const auto& it : vec) {
        cout << it << " ";
    }
}
vector<int> NewMtrxPrintingWay_h (const vector<vector<int>>& vec) {
    vector<int> result;
    int n = vec.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == 0 && j <= n-1)
                result.push_back({0});
            if(i == 1 && j < 1)
                result.push_back({0});
            if(i == 1 && j <= n-1-i-1)
                result.push_back({1});

        }
    }
    cout << "\n";
    return result;
}

int main() {

    auto vec = ReadVector("input_4.1.txt");
    MatrixPrintHorizontal(vec);

    auto vec_h = NewMtrxPrintingWay_h(vec);
    VectorPrint(vec_h);
    cout << "\n";
    VecWrite(8, 8, vec_h);

    auto new_mtrx = ReadVector("output_4.1.txt");
    MatrixPrintHorizontal(new_mtrx);

    return 0;
}


