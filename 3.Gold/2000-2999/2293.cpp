// 동전 1 - BOJ #2293

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k, temp;
    cin >> n >> k;

    vt<int> coins;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        coins.push_back(temp);
    }

    vt<int> dp(k +1, 0);
    dp[0] = 1;
    for(auto &i : coins) {
        for(int j = i; j <= k; j++) {
            dp[j] += dp[j -i];
        }
    }

    cout << dp[k];
}