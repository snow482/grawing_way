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



vector<int> ReadVector(const string& filePath){
    std::ifstream input {filePath};
    size_t n;
    input >> n;             // запись значений в файл input.txt
    vector<int> vec;        // пустой вектор
    vec.resize(n);          // емкость вектора увеличивается на колличество значений n

    for(int i=0;i<n;++i){
        input >> vec[i];    // запись этих значений в вектор
    }
    return vec;
}

int findMax(const vector<int>& vec){
    auto max = vec[0];             // принимаем максимальным значением вектора [0] элемент
    for(const auto& el : vec){     // проходимся по vec
        if(el > max)
            max = el;
    }
    return max;
}

int main(){
    auto vec = ReadVector("input.txt");
    std::ofstream out{"output.txt"};
    out << findMax(vec);

    return 0;
}