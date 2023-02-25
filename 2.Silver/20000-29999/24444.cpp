// 알고리즘 수업 - 너비 우선 탐색 2 - BOJ #24444

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

vector<int> graph[100001];
int visited[100001] = {0, };
queue<int> que;
int result[100001];
int cnt = 0;

void bfs(int r) {
    visited[r] = true;
    que.push(r);
    result[r] = ++cnt;

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        
        for(int i = 0; i < sz(graph[v]); i++) {
            int temp = graph[v][i];
            if(!visited[temp]) {
                result[temp] = ++cnt;
                que.push(temp);
                visited[temp] = true;
            }
        }
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
        sort(all(graph[i]));
    }
    
    bfs(r);

    for(int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }
}