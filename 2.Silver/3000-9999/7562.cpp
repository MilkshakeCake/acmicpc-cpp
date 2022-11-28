// 나이트의 이동 - BOJ #7562

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

vt<vt<int>> dp(301, vt<int>(301, -1));
vt<pii> moves = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};
int l, sx, sy, fx, fy;


void bfs() {
    queue<pii> que;

    que.push(make_pair(sx, sy));
    dp[sx][sy] = 1;
    
    while(dp[fx][fy] == -1) {
        pii v = que.front();
        que.pop();
        for(auto& i : moves) {
            if(v.fr + i.fr < 0 || v.sc + i.sc < 0 || v.fr + i.fr >= l || v.sc + i.sc >= l) continue;
            if(dp[v.fr + i.fr][v.sc + i.sc] != -1) continue;

            que.push(make_pair(v.fr + i.fr, v.sc + i.sc));
            dp[v.fr + i.fr][v.sc + i.sc] = dp[v.fr][v.sc] +1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        vt<vt<int>> empty(301, vt<int>(301, -1));
        dp.swap(empty);
        cin >> l >> sx >> sy >> fx >> fy;
        bfs();
        cout << dp[fx][fy] -1 << '\n';
    }
}