// 동전 1 - Baekjoon Online Judge #2293

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)

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