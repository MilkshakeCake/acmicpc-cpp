// 도미노 넘어뜨리기 - Baekjoon Online Judge #25633

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <fstream>
#include <map>

using namespace std;

int dom[1001] = {};
int dp[1001] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> dom[i];
        dp[i] = dp[i -1] + dom[i];
    }

    
}