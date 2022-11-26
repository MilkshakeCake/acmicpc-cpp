// 내리막 길 - Baekjoon Online Judge #1520

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

vt<vt<int>> field(502, vt<int>(502, -1));
vt<vt<ll>> dp(502, vt<ll>(502, -1));
const vt<pii> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int m, n;

ll dfs(int x, int y) {
    if(x < 1 || y < 1 || x > m || y > n) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    if(x == m && y == n) return 1;
    dp[x][y] = 0;
    for(auto& i : moves) {
        int nx = x + i.fr;
        int ny = y + i.sc;

        if(nx < 1 || ny < 1 || nx > m || ny > n) continue;
        if(field[nx][ny] >= field[x][y]) continue;

        if(dp[nx][ny] != -1) dp[x][y] += dp[nx][ny];
        else dp[x][y] += dfs(nx, ny);
    }

    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> field[i][j];
        }
    }
    
    cout << dfs(1, 1);
}