// DFS와 BFS - Baekjoon Online Judge #1260

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <fstream>
#include <sstream>
#include <map>

#define ll long long
#define ull unsigned long long
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
int visited[100001] = {0, };
int result[100001];
int cnt = 0;

void init() {
    for(int i = 0; i < 100001; i++) {
        graph[i].clear();
    }
}

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

void dfs(int r) {
    if(visited[r]) return;

    visited[r] = true;
    result[r] = ++cnt;

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
    
}