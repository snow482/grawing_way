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
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << mtrx[i][j] << "\t";
        }
        cout << endl;
    }
    return mtrx;
}

vector<vector<int>> TranspositionVector(const vector<vector<int>>& vec_a) {
    vector<vector<int>> vec_b;
    vec_b.resize(vec_a.size());

    for (int i = 0; i < vec_b.size(); ++i) {
        vec_b[i].resize(vec_a[i].size());
        for (int j = 0; j < vec_b.size(); ++j) {
            vec_b[j].resize(vec_a[j].size());
            vec_b[j][i] = vec_a[i][j];
        }
    }
    return vec_b;
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
    auto transpMatrix = TranspositionVector(vec);
    cout << endl;
    MatrixPrint(transpMatrix);


    return 0;
}
