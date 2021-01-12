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

int VectorMax(const vector<int>& vec){
    int max = vec[0];
    for(const auto& it : vec){
        if(max < it){
            max = it;
        }
    }
    return max;
}
int VectorMin (const vector<int>& vec){
    int min = vec[0];
    for(const auto& it : vec){
        if(min > it){
            min = it;
        }
    }
    return min;
}
vector<int> FindMaxVecValue(const vector<vector<int>>& vec){

    vector<int> max_value;
    /*for(const auto& row : vec){
       max_value.push_back(VectorMax(row));
    }*/
    for (int i = 0; i < vec.size(); ++i) {
       max_value.push_back(VectorMax(vec[i]));
    }
    return max_value;
}

int main(){

    auto vec = ReadVector("input.txt");
    std::ofstream out{"output.txt"};

    vector<int> vectr = FindMaxVecValue(vec);
    cout << "max value: " << VectorMax(vectr) << endl;
    cout << "min value: " << VectorMin(vectr) << endl;

    return 0;
}