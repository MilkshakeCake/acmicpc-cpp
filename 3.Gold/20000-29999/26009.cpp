// 해시 해킹 - BOJ #26008
// BOJ Contest 884 - 홍익대학교 PS 동아리 HI-ARC 2022

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

const vt<pii> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vt<vt<int>> board(3002, vt<int>(3002, 0));
int n, m, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    int r, c, d;
    while(k--) {
        cin >> r >> c >> d;
        board[r][c] = -1;

        for(int i = max(c - d, 1); i <= min(c + d, m); i++) {
            board[min(r + (d - abs(c - i)), n)][i] = -1;
            board[max(r - (d - abs(c - i)), 1)][i] = -1;
        }
    }

    queue<pii> q;
    board[1][1] = 0;
    q.push({1, 1});
    while(!q.empty()) {
        pii now = q.front();
        q.pop();
        for(auto& i : moves) {
            int nowX = now.fr + i.fr;
            int nowY = now.sc + i.sc;

            if(nowX < 1 || nowY < 1 || nowX > n || nowY > m) continue;
            if(board[nowX][nowY] != 0) continue;

            board[nowX][nowY] = board[now.fr][now.sc] + 1;
            q.push({nowX, nowY});
        }
    }

    if(board[n][m] != 0) cout << "YES" << '\n' << board[n][m];
    else cout << "NO";
}