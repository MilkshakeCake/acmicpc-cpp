// 파일 합치기 - BOJ #11066

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

const int INF = 1e9 + 7;

using namespace std;

int n, book[501];

vt<ll> psum(501, 0);
vt<vt<ll> > dp(501, vt<ll>(501, -1));

int cut(int l, int r) {
   return psum[r] - (l > 0 ? psum[l -1] : 0);
}

ll f(int l, int r) {
    ll& lr = dp[l][r];
    if(lr != -1) return lr;
    else if(l == r) return 0;

    lr = INF;

    for(int i = l; i < r; i++) {
        lr = min(lr, cut(l, i) + cut(i +1, r) + f(l, i) + f(i +1, r));
    }

    return lr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        
        for(int i = 0; i < n; i++) {
            cin >> book[i];
        }

        psum[0] = book[0];
        for(int i = 1; i < n; i++) {
            psum[i] = psum[i -1] + book[i];
        }

        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                dp[i][j] = -1;
            }
        }

        cout << f(0, n -1) << '\n';
    }

    return 0;
}