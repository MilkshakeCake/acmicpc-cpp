// 케빈 베이컨의 6단계 법칙 - BOJ #1389

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

vt<int> dist[101];
vt<int> graph[101];

void dijkstra(int start) {
    vt<int> cache(101, -1);
    cache[start] = 0;

    queue<int> que;
    que.push(start);
    while(!que.empty()) {
        int now = que.front();
        que.pop();

        for(auto &i : graph[now]) {
            if(cache[i] != -1) continue;
            cache[i] = cache[now] +1;
            que.push(i);
        }
    }

    dist[start] = cache;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    while(m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int minMem = 0;
    int kevin = 5555;

    for(int i = 1; i <= n; i++) {
        dijkstra(i);
        dist[i][0] = 0;
        for(int j = 1; j <= n; j++) {
            dist[i][0] += dist[i][j];
        }

        if(dist[i][0] < kevin) {
            minMem = i;
            kevin = dist[i][0];
        }
    }

    cout << minMem;
}