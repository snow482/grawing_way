
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*Вместо вектора сделать матрицу
найти максимум в каждой строке этой матрицы
среди максимумов строк матрицы найти минимальное значение*/
// вывод в консоль минимума


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

int FindMinFromMaxVecValue(const vector<vector<int>>& vec) {
    int min = INT_MAX;

    for (int i = 0; i < vec.size(); ++i) {
        int max = INT_MIN;
        for (int j = 0; j < vec[i].size(); ++j) {
            if(max < vec[i][j]){
                max = vec[i][j];
            }
        }
        std::cout << max <<std::endl;
        if(min > max){
            min = max;
        }
    }
    return min;
}

int main(){

    auto vec = ReadVector("input.txt");
    auto values = FindMinFromMaxVecValue(vec);
    cout << "min value: " << values << endl;

    return 0;
}
