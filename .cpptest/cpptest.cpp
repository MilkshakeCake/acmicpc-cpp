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
    string str;
    cin >> str;
    vector<int> vs;
    
    int start = 0;
    for(int i = 0; i < (int)str.length(); i++) {
        if(str[i] == '+') {
            vs.push_back(stoi(str.substr(start, i)));
            start = i;
        }
        if(i == (int)str.length() - 1) {
            vs.push_back(stoi(str.substr(start)));
        }
    }

    for(auto& i : vs) cout << i << ' ';
}