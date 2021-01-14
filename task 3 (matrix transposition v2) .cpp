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

vector<vector<int>> TranspositionVector(vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i + 1; j < vec.size(); ++j) {
            int tmp = vec[i][j];
            vec[i][j] = vec[j][i];
            vec[j][i] = tmp;
        }
    }
    return vec;
}

void MatrixPrint(vector<vector<int>> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size(); ++j) {
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(){

    auto vec = ReadVector("input.txt");
    MatrixPrint(vec);
    auto transpMatrix = TranspositionVector(vec);
    cout << endl;
    MatrixPrint(transpMatrix);

    return 0;
}
