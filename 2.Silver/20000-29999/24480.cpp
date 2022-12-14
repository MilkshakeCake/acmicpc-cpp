// 알고리즘 수업 - 깊이 우선 탐색 2 - BOJ #24480

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

vector<int> graph[100001];
int visited[100001] = {0, };
int result[100001];
int cnt = 0;

void dfs(int r) {
    if(visited[r]) return;

    visited[r] = true;
    result[r] = ++cnt;

    for(int i = 0; i < sz(graph[r]); i++) {
        dfs(graph[r][i]);
    }
}

int main() {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    for(int i = 1; i <= m; i++) {
        int s, f;
        scanf("%d %d", &s, &f);
        graph[s].push_back(f);
        graph[f].push_back(s);
    }
    
    for(int i = 1; i <= n; i++) {
        sort(all(graph[i]), greater<>());
    }
    
    dfs(r);

    for(int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }
}