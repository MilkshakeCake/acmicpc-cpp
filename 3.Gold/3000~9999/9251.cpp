// lcs - BOJ #9251

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

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