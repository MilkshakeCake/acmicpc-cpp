// 이분 그래프 - BOJ #1707
// bipartite graph

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

using namespace std;

vt<int> graph[20001];
vt<int> color(20001, -1);
int K, V, E;

void init() {
    for(int i = 1; i <= V; i++) {
        graph[i].clear();
        color[i] = -1;
    }
}

bool bfs(int x) {
    queue<int> que;
    que.push(x);
    color[x] = 0;

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for(auto& i : graph[v]) {
            if(color[i] != -1) {
                if(color[i] == color[v]) {
                    return false;
                }
                continue;
            }

            que.push(i);
            color[i] = (color[v] + 1) %2;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> K;
    while(K--) {
        init();
        cin >> V >> E;
        while(E--) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool flag = true;
        for(int i = 1; i <= V; i++) {
            if(color[i] == -1) flag = bfs(i);
            if(!flag) break;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}