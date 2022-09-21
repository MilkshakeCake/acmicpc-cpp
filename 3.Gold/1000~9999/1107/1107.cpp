// 리모컨 - Baekjoon Online Judge no.1107

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

vector<bool> arr(10, true);
vector<int> v;
string n;
int m;
int cnt = 0;

void recursive(int num, int save) {
    if(arr[num]) {
        v.push_back(num);
        cnt++;
    }
    else {
        num == 9 ? recursive(0, save) : recursive(num + 1, save);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    while(m--) {
        int temp;
        cin >> temp;
        arr[temp] = false;
    }

    for(int i = 0; i < (int)n.length(); i++) {
        recursive((int)n[i] - 48, 0);
    }

    int tencnt = 1;
    int sum = 0;
    for(int i = (int)v.size() - 1; i >= 0; i--) {
        sum += v[i] * tencnt;
        tencnt *= 10;
    }
    cnt += abs(sum - stoi(n));
    cout << (abs(stoi(n) - 100) < cnt ? abs(stoi(n) - 100) : cnt);
}