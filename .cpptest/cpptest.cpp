// Practice techniques of C++

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <map>

using namespace std;

int main() {
    vector<vector<int> > v;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    v.push_back(temp);
    temp.pop_back();
    temp.pop_back();
    temp.push_back(30);
    temp.push_back(40);
    v.push_back(temp);
    for(auto& i : v) cout << v[i];
}