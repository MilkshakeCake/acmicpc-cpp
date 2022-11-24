// 경찰차 - Baekjoon Online Judge #2618
// DP + BFS
// INCOMPLETE

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
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

int N;
const vt<pii> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int bfs(pii start, pii end) {
    vt<vt<int>> visited(N, vt<int>(N, 0));
    queue<pii> que;
    que.push(start);
    visited[start.fr][start.sc] = 0;

    while(!que.empty()) {
        pii top = que.front();
        que.pop();

        for(auto &i : moves) {
            int nx = top.fr + i.fr;
            int ny = top.sc + i.sc;
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(visited[nx][ny]) continue;

            que.push({nx, ny});
            visited[nx][ny] = visited[top.fr][top.sc] +1;
        }
    }

    return visited[end.fr][end.sc];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int W;
    cin >> N >> W;
    vt<int> dp(W, 0);
    
    pii patrol1 = {0, 0};
    pii patrol2 = {N -1, N -1};
    vt<vt<int>> city(N, vt<int>(N, 0));
    vt<int> output;
    
    pii incident;
    while(W--) {
        cin >> incident.fr >> incident.sc;
        int dist1 = bfs(patrol1, incident);
        int dist2 = bfs(patrol2, incident);


    }
}