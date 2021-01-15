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

void VectorPrint(const vector<int>& vec) {
    for(const auto& it : vec) {
        cout << "result vector: " << it << " ";
    }
}
vector<int> MultiplyingMtrxByVec (const vector<vector<int>> mtrx_vec, const vector<int>& vec) {
    vector<int> result_vec(vec.size()); // casting result_vec size to vec.size()

    int n = mtrx_vec.size();

    for (int i = 0; i < n; ++i) {
        result_vec[i] = 0;
        for (int j = 0; j < n; ++j) {
            result_vec[i] += mtrx_vec[i][j] * vec[j];
        }
    }

    return result_vec;
}

int main(){

    auto vec = ReadVector("input.txt");
    MatrixPrint(vec);
    vector<int> vec_for_multiply = {1,2,3};

    vector<int> result_vec = MultiplyingMtrxByVec(vec, vec_for_multiply);
    VectorPrint(result_vec);

    return 0;
}


