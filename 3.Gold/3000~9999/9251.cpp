// lcs - Baekjoon Online Judge no.9251

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

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)

using namespace std;

int dp[1001][1001] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string a;
    string b;
    cin >> a >> b;

    for(int i = 1; i <= sz(a); i++) {
        for(int j = 1; j <= sz(b); j++) {
            if(a[i -1] == b[j -1]) dp[i][j] = dp[i -1][j -1] + 1;
            
            else dp[i][j] = max(dp[i -1][j], dp[i][j -1]);
        }
    }

    cout << dp[sz(a)][sz(b)];
}