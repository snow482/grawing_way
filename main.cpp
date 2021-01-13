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

std::pair<int,int> FindMaxVecValue(const vector<vector<int>>& vec){
    int max_value = 0;
    int min_value = 100500;
    for (int i = 0; i < vec.size(); ++i) {
        int max = vec[i][0];
        for (int j = 0; j < vec.size(); ++j) {
            if(max < vec[0][j]){
                min_value = max_value = max = vec[i][j];
            }
            if (min_value > vec[i][0]){
                min_value = vec[i][j];
            }
        }
    }
    return std::make_pair(max_value, min_value);
}

int main(){

    auto vec = ReadVector("input.txt");
    auto values = FindMaxVecValue(vec);
    cout << "max value: " << values.first<< endl;
    cout << "min value: " << values.second<< endl;

    /*vector<int> vectr = FindMaxVecValue(vec);
    cout << "max value: " << VectorMax(vectr) << endl;
    cout << "min value: " << VectorMin(vectr) << endl;*/

    return 0;
}