#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    vector<int> v;
    for(int i = 0; i < 10; i++) {
        v.push_back(i);
        cout << v[i] << ' ';
    }
    cout << '\n';

    v.erase(v.begin());
    v.pop_back();
    for(unsigned int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }

}