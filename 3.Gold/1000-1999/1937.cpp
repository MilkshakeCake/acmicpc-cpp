// 트리의 지름 - BOJ #1937

#include <bits/stdc++.h>

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

using namespace std;

struct Node {
    int idx, dist;
};

int v, maxD, maxN;
vt<Node> graph[100001];
vt<bool> visited(100001, false);

void dfs(int node, int dist) {
    if(visited[node]) return;
    if(maxD < dist) {
        maxD = dist;
        maxN = node;
    }
    visited[node] = true;

    for(auto i : graph[node]) {
        dfs(i.idx, i.dist + dist);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> v;
    int from, to, dist;
    for(int i = 1; i < v; i++) {
        cin >> from >> to >> dist;
        graph[from].push_back({to, dist});
        graph[to].push_back({from, dist});
    }

    dfs(1, 0);
    vt<bool> newv(100001, false);
    visited = newv;
    maxD = 0;
    dfs(maxN, 0);

    cout << maxD;
}