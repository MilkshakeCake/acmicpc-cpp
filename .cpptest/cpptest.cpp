// Practice techniques of C++

#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <map>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main() {
    vector<int> v;
    for(int i = 0; i < 5; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    v.erase(v.begin() + 3);
    for(auto& i : v) cout << i << ' ';
}