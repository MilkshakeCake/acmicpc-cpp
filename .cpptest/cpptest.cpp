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
    vector<vector<int> > bigV;
    vector<int> smallV1;
    vector<int> smallV2;
    for(int i = 0; i < 5; i++) {
        smallV1.push_back(i);
    }
    bigV.push_back(smallV1);

    for(int i = 1; i < 6; i++) {
        smallV2.push_back(i*10);
    }
    bigV.push_back(smallV2);

    cout << bigV[1][1];
}