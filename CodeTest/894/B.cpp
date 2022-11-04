#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define fac 362880

using namespace std;

int main() {
    vector<double> v;
    double temp;
    for(int i = 0; i < 10; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), greater<>());
    v.pop_back();
    double result = 1e9 / fac;
    for(int i = 0; i < 9; i++) { 
        result *= v[i];
    }
    cout.precision(7);
    cout << result;
}
    