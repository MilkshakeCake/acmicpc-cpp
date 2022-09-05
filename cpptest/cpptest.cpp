#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    string str = "abcde";
    int hash = 0;
    int temp;
    for(int i = 0; i < 5; i++) {
        temp = (str[i] - 96) * pow(31, i);
        hash += temp;
        cout << str[i] - 96 << ' ' << pow(31, i) << ' ' << temp << ' ' << hash << '\n';
    }

    cout << hash - 1;
}