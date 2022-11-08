#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <deque>
#include <numeric>
#include <map>
#include <stack>
#define ll long long
using namespace std;
int M,N,ans;
int board[550][550];
int dp[550][550];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct info{
    int y;
    int x;
};
// dp[y][x] = y,x부터 M-1 N-1까지 가는 경우의 수
int DFS(int y, int x){
    if(dp[y][x] != -1) return dp[y][x]; // dp결과가 있으면 바로 return
    if(y == M-1 and x == N-1) return 1; // 최종 목적지로 도착하면 종료
    dp[y][x] = 0;
    for(int dir=0;dir<4;dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(nx<0 or ny<0 or nx>=N or ny>=M) continue;
        if(board[ny][nx] >= board[y][x]) continue;
        // dp값이 있으면 바로 더하기
        if(dp[ny][nx] != -1){
            dp[y][x] += dp[ny][nx];
        }else{
            // dp값이 없으면 구해와서 더하기
            dp[y][x] += DFS(ny,nx);
        }
    }
    return dp[y][x];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N; // M=세로, N=가로
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
        {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    ans = DFS(0,0);
    cout << ans;
    return 0;
}