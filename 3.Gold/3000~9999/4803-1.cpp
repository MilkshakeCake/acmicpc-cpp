// 트리 - BOJ #4803 v2
// edge visit confirm dfs

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

vt<int> graph[501];
vt<bool> visited(501, 0);
vt<vt<bool>> edge(501, vt<bool>(501, 0));

bool dfs(int r) {
    if(visited[r]) return false;
    visited[r] = true;

    for(auto &i : graph[r]) {
        if(edge[r][i] || edge[i][r]) continue;
        edge[r][i] = true;
        edge[i][r] = true;
        if(!dfs(i)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, from, to, cnt(0), T(0);
    scanf("%d %d", &n, &m);
    
    while(n != 0 || m != 0) {
        for(int i = 0; i < m; i++) {
            cin >> from >> to;

            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        for(int i = 1; i <= n; i++) sort(all(graph[i]));

        for(int i = 1; i <= n; i++) {
            if(visited[i] || !dfs(i)) continue;
            T++;
        }

        printf("Case %d : ", ++cnt);
        if(T == 0) printf("No trees.\n");
        else if (T == 1) printf("There is one tree.\n");
        else printf("A forest of %d trees.\n", T);

        for(int i = 1; i <= n; i++) graph[i].clear();
        for(int i = 1; i <= n; i++) visited[i] = false;
        for(auto &i : edge) i.assign(501, 0);
        T = 0;

        scanf("%d %d", &n, &m);
    }

    return 0;
}