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

int FindMaxFromMinValue (const vector<vector<int>> vec) {
    int max = INT_MIN;
    int min = INT_MAX;
    int n = vec.size();

    // --------- цикл бегущий по столбцам -----------
    /*for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size(); ++j) {
            cout << vec[j][i] << " ";
        }
        cout << endl;
    }*/
    for (int j = 0; j < n; ++j) {
        for (int i = n - j - 1; i < n; ++i) {
            cout << vec[i][j] << " ";
            if(min > vec[i][j]) {
                min = vec[i][j];
            }
        }
        if(max < min) {
            max = min;

        }
    }
    cout << "\n" << "min: " << min <<" max: " << max << endl;

    return max;
}




int main(){

    auto vec = ReadVector("input.txt");
    MatrixPrint(vec);
    cout << "\n" << FindMaxFromMinValue(vec) << endl;

    return 0;
}


