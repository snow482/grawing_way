#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;


/*У тебя есть тестовый файл input.txt в нём записано, n - количество чисел
А дальше сами числа. Требуется найти максимум и вывести его в файл output.txt

Пример
input.txt
3
1 2 3
output.txt
3*/

/*Вместо вектора сделать матрицу
найти максимум в каждой строке этой матрицы
среди максимумов строк матрицы найти минимальное значение*/
// вывод в консоль


vector<vector<int>> ReadVector(const string& filePath){
    std::ifstream input {filePath};
    size_t n, m;
    input >> n;                            // row
    input >> m;                            // colomn
    vector<vector<int>> mtrx(n, vector<int>(m));

    for(int i=0; i<n; ++i){
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

int FindMaxVecValue(const vector<vector<int>>& vec){
    int min = INT_MAX;

    for (int i = 0; i < vec.size(); ++i) {
        int max = INT_MIN;
        for (int j = 0; j < vec[i].size(); ++j) {
            if(max < vec[i][j]){
                max = vec[i][j];
            }
        }
        std::cout << max<<std::endl;
        if(min > max){
            min = max;
        }

    }
    return min;
}


int main(){

    auto vec = ReadVector("input.txt");
    auto values = FindMaxVecValue(vec);
    cout << "min value: " << values << endl;

    /*vector<int> vectr = FindMaxVecValue(vec);
    cout << "max value: " << VectorMax(vectr) << endl;
    cout << "min value: " << VectorMin(vectr) << endl;*/

    return 0;
}