#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

// print maxtrix from 1 to 9 like showed below
/*
 * 4 2 1
 * 7 5 3
 * 9 8 6
*/

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

vector<int> CrazyMtrxPrintingWay (const vector<vector<int>>& vec) {
    vector<int> result;
    int n = vec.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n-1-j; ++j) {
            cout << vec[i][j+2] << " ";   // 1
            cout << vec[i][j+1] << " ";   // 2
            cout << vec[i+1][j+2] << " "; // 3
            cout << vec[i][j] << " ";     // 4
            cout << vec[i+1][j+1] << " "; // 5
            cout << vec[i+2][j+2] << " "; // 6
            cout << vec[i+1][j] << " ";   // 7
            cout << vec[i+2][j+1] << " "; // 8
            cout << vec[i+2][j] << " ";   // 9
        }
        cout << "\n";
    }

    // -------------------------работает---------------------------//
/*    for (int k = 2; k < n; ++k) {
        for (int i = 0; i < n-k; ++i) {
            *//*std::cout << i <<" "<<i+k<<std::endl;*//*
            cout << vec[i][i+k] << " ";
        }
        cout << " / ";
        for (int i = 0; i < n-1; ++i) {
            cout << vec[i][i+1] << " ";
        }
        cout << " / ";
        for (int i = 0; i < n; ++i) {
            cout << vec[i][i] << " ";
        }
        cout << " / ";
        for (int i = 0; i < n-1; ++i) {
            cout << vec[i+1][i] << " ";
        }
        cout << " / ";
        for (int i = 0; i < n-k; ++i) {
            cout << vec[i+k][i] << " ";
        }
    }*/

    // -----------------------------------------------------------//

  /*for (int i = 0; i < n; ++i) {
       cout << vec[i][i] << " ";
    }
    cout << " / ";
    for (int i = 0; i < n-1; ++i) {
        cout << vec[i][i+1] << " ";
    }
    cout << " / ";
    for (int i = 0; i < n-2; ++i) {
        cout << vec[i][i+2] << " ";
    }
    cout << " / ";
    for (int i = 0; i < n-1; ++i) {
        cout << vec[i+1][i] << " ";
    }
    cout << " / ";
    for (int i = 0; i < n-2; ++i) {
        cout << vec[i+2][i] << " ";
    }*/

    return result;
}

int main(){

    auto vec = ReadVector("input_2.txt");
    MatrixPrint(vec);
    auto vec_new = CrazyMtrxPrintingWay(vec);
    VectorPrint(vec_new);


    return 0;
}


