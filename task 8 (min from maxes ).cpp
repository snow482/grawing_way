#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <assert.h>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

vector<vector<int>> VectorRead (const string& path){
    std::ifstream input {path};
    size_t n, m;
    input >> n;
    input >> m;
    vector<vector<int>> mtrx(n, vector<int>(m));

    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) {
            input >> mtrx[i][j];
        }
    }
    return mtrx;
}

void VecPrinter(const vector<int>& vec){
    for(const auto& it : vec)
        cout << it << " ";
}
void MtrxPrint(const vector<vector<int>>& mtrx){
    for (int i = 0; i < mtrx.size(); ++i) {
        for (int j = 0; j < mtrx.size(); ++j) {
            cout << mtrx[i][j] << "\t";
        }
        cout << endl;
    }
}

int MinFromHighestTriangleMaxes(const vector<vector<int>>& mtrx){
    vector<int> result;
    vector<int> max_high;
    vector<int> max_low;
    int h = mtrx.size();
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < h; ++j) {
            if (i <= j) {
                max_high.push_back(mtrx[i][j]);
            }
            if (i >= j) {
                max_low.push_back(mtrx[i][j]);
            }
        }
    }
    int max_h = max_high[0];
    for(const auto& it_h : max_high){
        if(max_h < it_h){
            max_h = it_h;
        }
    }
    result.push_back(max_h);

    int max_l = max_low[0];
    for (int i = 0; i < max_low.size(); ++i) {
        if(max_l < max_low[i]){
            max_l = max_low[i];
        }
    }
    result.push_back(max_l);
    int min = result[0];
    for (int i = 0; i < result.size(); ++i) {
        if(min > result[i]){
            min = result[i];
        }
    }

    VecPrinter(max_high);
    cout << "\n";
    VecPrinter(max_low);
    cout << "\n";
    VecPrinter(result);
    cout << "\n";
    return min;
}





int main(){

    auto mtrx = VectorRead("input.txt");
    MtrxPrint(mtrx);
    /*VecPrinter(VecFromLowestTriangle(mtrx));*/
    /*auto low_vec = VecFromLowestTriangle(mtrx);
    VecPrinter(low_vec);*/
    cout << MinFromHighestTriangleMaxes(mtrx);




    /*auto vec = ReadVector("input.txt");
    MatrixPrint(vec);
    cout << "\n" << FindMaxFromMinValue(vec) << endl;*/

    return 0;
}


