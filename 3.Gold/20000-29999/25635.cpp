// 자유 이용권 - BOJ #25635

#include <bits/stdc++.h>
#include <map>

using namespace std;

long long play[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    long long sum = 0;
    long long maxn = 0;
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