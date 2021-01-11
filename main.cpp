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

int findMax(const vector<vector<int>>& vec, const string& filePath){
    std::ofstream output{filePath};
    size_t n, m;
    output << n;
    output << m;

    int max_value;
    int max[n];
    max[0] = vec[0][0];                   // принимаем максимальным значением матрицы элемент [0][0]
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size(); ++j) {
            if(max[i] < vec[i][j])
                max[i] = vec[i][j];
                max_value = max[i];
        }
        cout << "max value in rows: " << max[i] << " ";
    }

    return max_value;
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

int main(){

    auto vec = ReadVector("input.txt");
    std::ofstream out{"output.txt"};
    vector<int> vectr = {1, 2, 3, 2, 4, 5, 6, 8, 5};
    VectorMax(vectr);
    out << findMax(vec, "input.txt");


    return 0;
}