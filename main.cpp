#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::ws;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;



/*У тебя есть тестовый файл input.txt в нём записано, n - количество чисел
А дальше сами числа. Требуется найти максимум и вывести его в файл output.txt

Пример
input.txt
3
1 2 3
output.txt
3*/


void FileReading(const string& filePath, vector<int>& vec){
    ifstream input (filePath);
    while(!input.eof()) {
        int n;
        input >> n >> ws;
        vec.push_back(n);
    }
    input.close();
}

void FileWriting(const string& filePath){
    ofstream output(filePath);
    if(output){
        cout << "Please, write a numbers below:" << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int nums;
            cin >> nums;
            output << nums << " ";
        }
    }else{
        cout << "error" << endl;
    }
    output.close();
}

void VectorPrinting(const vector<int>& vec){
    for(auto it : vec){
        cout << it << endl;
    }
}

int MaxSort(const vector<int>& vec){
    auto it_max = vec.begin();
    for(auto it = vec.begin(); it != vec.end(); ++it){
        if(*it_max < *it){
            it_max = it;
        }
    }
    return *it_max;
}

int main(){

    string filePath = "input.txt";
    vector<int> vec;
    FileWriting(filePath);
    FileReading(filePath, vec);
    VectorPrinting(vec);

    int m = 0;
    MaxSort(vec);
    m = MaxSort(vec);
    cout << "max value: " << m << endl;




    //-------------------шляпа---------------------------
    /*ofstream output;
    output.open(filePath);

    if(output.is_open()){
        cout << "Please, write a numbers below " << endl;
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int nums;
            cin >> nums;

            output << nums << " ";
        }
    }else {
        cout << "error" << endl;
    }
    output.close(); */

    /*ifstream input;
    input.open(filePath);
    if(input.is_open()){
        FileReading(filePath);
    }else{
        cout << "error" << endl;
    }
   *//* if(input.is_open()){
        string m;
        vector<string> numVec;
        while(getline(input, m)){
           numVec.push_back(m);
        }

    }else{
        cout << "error" << endl;
    }*//*

    input.close();
*/
    //-------------------шляпа---------------------------


    return 0;
}