// DFS와 BFS - Baekjoon Online Judge #1260

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

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)

using namespace std;

vector<int> graph[100001];
queue<int> que;
bool visited[100001] = {0, };
int result[100001];
int cnt = 0;
queue<int> output;

void init() {
    cnt = 0;
    for(int i = 0; i < 100001; i++) {
        visited[i] = false;
    }
}

void bfs(int r) {
    visited[r] = true;
    que.push(r);
    output.push(r);

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        
        for(int i = 0; i < sz(graph[v]); i++) {
            int temp = graph[v][i];
            if(!visited[temp]) {
                output.push(temp);
                que.push(temp);
                visited[temp] = true;
            }
        }
    }
}

void dfs(int r) {
    if(visited[r]) return;

    visited[r] = true;
    output.push(r);

    for(int i = 0; i < sz(graph[r]); i++) {
        dfs(graph[r][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, v;
    cin >> n >> m >> v;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) sort(all(graph[i]));

    dfs(v);
    while(sz(output)) {
        cout << output.front() << ' ';
        output.pop();
    }
    cout << '\n';

    init();

    bfs(v);
    while(sz(output)) {
        cout << output.front() << ' ';
        output.pop();
    }
}