#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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


void FileReading(const string& filePath){
    ifstream input (filePath);
    vector<string> vec;
    if(input){
        string line;
        while(getline(input, line)){
            vec.push_back(line);
        }
        for(auto n : vec){
            cout << n << endl;
        }

    }else{
        cout << "error" << endl;
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

int main(){

    string filePath = "D:/C++/git/grawing_way/input.txt";
    FileWriting(filePath);
    FileReading(filePath);




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