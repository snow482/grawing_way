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


void MatrixPrint(vector<vector<int>>& vec) {
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

vector<int> MultiplyingMtrxByVec (const vector<vector<int>>& mtrx_vec_a,
                                  const vector<vector<int>>& mtrx_vec_b) {
    vector<int> result_mtrx;
    vector<int> result_vec(mtrx_vec_a.size());  // casting result_vec size to mtrx_vec.size()
    vector<int> middle_vec;
    vector<int> firstThreeElements;
    vector<int> secondThreeElements;
    vector<int> thirdThreeElements;

    int n = mtrx_vec_a.size();
    int m = mtrx_vec_b.size();

    // идея, вытащить из второй матрицы первый столбец и запулить, как вектор
    // и перемножать матрицу на его первых 3 элемента, затем на вторые 3, затем на третьи 3

    // tramsform 2nd matrix to the vector
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            middle_vec.push_back(mtrx_vec_b[j][i]);
        }
    }
    // cutting first 3 elements
    for (int i = 0; i < middle_vec.size() - 6; ++i) {
        firstThreeElements.push_back(middle_vec[i]);
    }
    // cutting second 3 elements
    for (int i = 3; i < middle_vec.size() - 3; ++i) {
        secondThreeElements.push_back(middle_vec[i]);
    }
    // cutting third 3 elements
    for (int i = 6; i < middle_vec.size(); ++i) {
        thirdThreeElements.push_back(middle_vec[i]);
    }

    // matrix by vector multiplying start
    for (int i = 0; i < n; ++i) {
        result_vec[i] = 0;
        for (int j = 0; j < n; ++j) {
            result_vec[i] += mtrx_vec_a[i][j] * firstThreeElements[j];
        }
        result_mtrx.push_back(result_vec[i]);
    }
    for (int i = 0; i < n; ++i) {
        result_vec[i] = 0;
        for (int j = 0; j < n; ++j) {
            result_vec[i] += mtrx_vec_a[i][j] * secondThreeElements[j];
        }
        result_mtrx.push_back(result_vec[i]);
    }
    for (int i = 0; i < n; ++i) {
        result_vec[i] = 0;
        for (int j = 0; j < n; ++j) {
            result_vec[i] += mtrx_vec_a[i][j] * thirdThreeElements[j];
        }
        result_mtrx.push_back(result_vec[i]);
    }

    return result_mtrx;
}

int main(){

    auto vec_a = ReadVector("input.txt");
    MatrixPrint(vec_a);
    cout << "\n";
    auto vec_b = ReadVector("input_1.txt");
    MatrixPrint(vec_b);
    auto result_mtrx = MultiplyingMtrxByVec(vec_a, vec_b);
    VectorPrint(result_mtrx);

    return 0;
}


