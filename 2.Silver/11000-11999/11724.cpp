// 연결 요소의 개수 - BOJ #11724

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

vector<int> graph[1001];
vector<bool> visited(1001, false);

void dfs(int idx) {
    visited[idx] = true;
    for(auto &i : graph[idx]) {
        if(!visited[i]) dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    scanf("%d %d", &n, &m);

    while(m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}