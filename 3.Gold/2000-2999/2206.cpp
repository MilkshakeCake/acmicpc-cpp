// 벽 부수고 이동하기 - BOJ #2206

#include <bits/stdc++.h>
#include <queue>

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

#define INF 1e9

using namespace std;

const vt<pii> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vt<vt<bool>> board(1002, vt<bool>(1002, 1));
int trail[2][1002][1002] = {0};
queue<vt<int>> que;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string input;
        cin >> input;
        for(int j = 1; j <= m; j++) {
            board[i][j] = (int)input[j -1] - 48;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            trail[0][i][j] = INF;
            trail[1][i][j] = INF;
        }
    }
    
    que.push({0, 1, 1});
    trail[0][1][1] = 1;
    trail[1][1][1] = 1;

    while(!que.empty()) {
        auto now = que.front();
        que.pop();

        for(auto& i : moves) {
            int status = now[0];
            int nx = now[1] + i.fr;
            int ny = now[2] + i.sc;

            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;

            if(board[nx][ny] == 1) {
                if(status == 0) status = 1;
                else continue;
            }

            if(trail[status][nx][ny] <= trail[now[0]][now[1]][now[2]] +1) continue;

            que.push({status, nx, ny});
            trail[status][nx][ny] = trail[now[0]][now[1]][now[2]] +1;
        }
    }

    int ret = min(trail[0][n][m], trail[1][n][m]);
    if(ret == INF) cout << -1;
    else cout << ret;
}