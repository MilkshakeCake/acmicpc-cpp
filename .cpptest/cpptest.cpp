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
    vector<int> v(10, 0);
    v.push_back(1);
    for(auto& i : v) cout << i << ' ';
}