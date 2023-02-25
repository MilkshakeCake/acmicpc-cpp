// 트리 - BOJ #4803

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

vt<int> graph[501];
vt<int> visited(501, false);
bool flag = true;

void dfs(int r, int cnt) {
    visited[r] = cnt;

    for(auto i : graph[r]) {
        if(!visited[i]) dfs(i, cnt +1);
        else if(abs(visited[r] - visited[i]) > 1) flag = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, from, to, cnt(0), T(0);
    scanf("%d %d", &n, &m);
    while(n != 0) {
        while(m--) {
            scanf("%d %d", &from, &to);
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        for(int i = 1; i <= n; i++) {
            if(visited[i]) continue;
            flag = true;
            dfs(i, 0);
            T += flag;
        }

        printf("Case %d: ", ++cnt);
        if(T == 0) puts("No trees.");
        else if(T == 1) puts("There is one tree.");
        else printf("A forest of %d trees.\n", T);

        for(int i = 1; i <= n; i++) graph[i].clear();
        visited.assign(501, false);
        T = 0;

        scanf("%d %d", &n, &m);
    }

    return 0;
}