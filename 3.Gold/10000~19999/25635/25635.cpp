// 자유 이용권 - Baekjoon Online Judge #25635

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

int play[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int sum = 0;
    int maxn = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> play[i];
        sum += play[i];
        maxn = max(maxn, play[i]);
    }

    sum -= maxn;

    long long res = min(sum +1, maxn) + sum;
    cout << res;
}