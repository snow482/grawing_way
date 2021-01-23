#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main(){

    vector<int> vecNotDev;
    int n = 10;
    for (int i = 2; i <= n; ++i) {
        bool isPrime = true;
        for (int j = 2; j < i; ++j) {
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            vecNotDev.push_back(i);
        }
    }
    for(const auto& it : vecNotDev)
        cout << it << " ";

    return 0;
}
