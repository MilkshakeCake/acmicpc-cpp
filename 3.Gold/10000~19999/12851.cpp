// 숨바꼭질 2 - Baekjoon Online Judge #12851

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

vector<int> grid(100001, -1);
int n, k, cnt = 0;

void minDis() {
    queue<int> que;

    que.push(n);
    grid[n] = 0;

    while(!que.empty()) {
        int now = que.front();
        que.pop();
        
        for(int i : {now -1, now +1, now *2}) {
            if(i < 0 || i > 100000) continue;
            if(grid[i] != -1) continue;
            que.push(i);
            grid[i] = grid[now] +1;
        }
    }
}

void dfs(int now, int dist) {
    if(now == n && dist == 0) cnt++;
    else {
        for(int i : {now -1, now +1, now /2}) {
            if(i < 0 || i > 100000) continue;
            if(grid[(i == now /2 ? (now %2 == 0 ? i : now) : i)] +1 == grid[now]) dfs(i, dist -1);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;

    minDis();
    dfs(k, grid[k]);
    cout << grid[k] << '\n' << cnt;
}