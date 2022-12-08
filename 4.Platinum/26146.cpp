// 즉흥 여행 - BOJ #26146
// SCC(Strongly Connected Components)

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

int N, M;
bool flag = true;
vt<int> graph[200001];
vt<int> rev[200001];
vt<int> scc;
vt<bool> visited(200001, false);
stack<int> stk;

void dfs(int now, bool reverse) {
    if(visited[now]) return;
    visited[now] = true;

    for(auto &i : (reverse ? rev[now] : graph[now])) if(!visited[i]) dfs(i, reverse);
    reverse ? scc.push_back(now) : stk.push(now);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    int v, w;
    while(M--) {
        cin >> v >> w;
        graph[v].push_back(w);
        rev[w].push_back(v);
    }

    for(int i = 1; i <= N; i++) dfs(i, false);

    visited.assign(200001, false);

    dfs(stk.top(), true);

    cout << (sz(scc) == N ? "Yes" : "No");
}