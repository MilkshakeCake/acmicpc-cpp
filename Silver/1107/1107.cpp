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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool arr[10];
    for(int i = 0; i < 10; i++) {
        arr[i] = true;
    }
    
    string n;
    int m;
    cin >> n >> m;
    while(m--) {
        int temp;
        cin >> temp;
        arr[temp] = false;
    }

    int chan = 100;
    int cnt = 0;

    for(unsigned int i = 0; i < n.length(); i++) {
        if(arr[n[i]]) {
            cnt++;
        }
        else {
            
        }
    }
}