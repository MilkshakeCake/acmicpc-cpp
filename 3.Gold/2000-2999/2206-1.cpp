#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>

#define INF 1e9

using namespace std;

char board[1001][1001];
int cost[2][1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0 , -1, 0};
queue<pair<pair<int,int>,int>> q;
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> board[i][j];
        }
    }

    for(int d=0;d<2;d++) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                cost[d][i][j] = INF;
            }
        }
    }

    q.push({{0,0},0});
    cost[0][0][0] = 1;
    cost[1][0][0] = 1;
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++)
        {
            int nx = cur.first.second + dx[dir];
            int ny = cur.first.first + dy[dir];
            int status = cur.second;
            if(nx<0 or ny<0 or nx>=M or ny>=N) continue;
            if(board[ny][nx] == '1'){
                if(status == 0) status=1;
                else continue;
            }
            if(cost[status][ny][nx] <= cost[cur.second][cur.first.first][cur.first.second]+1) continue;
            q.push({{ny, nx}, status});
            cost[status][ny][nx] = cost[cur.second][cur.first.first][cur.first.second] + 1;
            if(ny == N-1 and nx == M-1) goto stop;
        }
    }
    stop:
    ans = min(cost[0][N-1][M-1], cost[1][N-1][M-1]);
    if(ans == INF) cout << -1;
    else cout << ans;
    return 0;
}