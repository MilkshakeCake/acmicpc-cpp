// 포도주 시식 - BOJ #2156

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define pll pair<long, long>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << ' '

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define EACH(x, a) for (auto& x : a)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int wine[10001] = {0};
    for(int i = 0; i < n; i++) {
        cin >> wine[i];
    }
    wine[n] = 0;

    int dp[10001] = {0};
    dp[0] = wine[0];
    dp[1] = wine[1] + wine[0];
    dp[2] = wine[2] + wine[0];
    for(int i = 3; i <= n; i++) {
        dp[i] = wine[i] + max(dp[i-3] + wine[i-1], dp[i-2]);
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n];
}