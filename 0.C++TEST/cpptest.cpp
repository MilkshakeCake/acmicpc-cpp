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
    vector<int> vt;
    for(int i = 0; i < 10; i++) {
        vt.push_back(i * (10 - i));
    }

    sort(all(vt), less<>());
    for(auto& i : vt) cout << i << ' ';
}