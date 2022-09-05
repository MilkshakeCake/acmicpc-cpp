#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    string str;
    getline(cin, str, '.');
    cout << str.substr(str.find('[') + 1, str.find(']') - str.find('[') - 1);
}