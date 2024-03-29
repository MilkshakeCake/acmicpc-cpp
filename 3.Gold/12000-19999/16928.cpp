// 뱀과 사다리 게임 - BOJ #16928

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

vt<int> snl(102, 0);
vt<vt<int>> graph(102);

void bfs() {
    queue<int> que;
    
    que.push(1);
    snl[1] = 0;

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        // for(auto& i : graph[v]) {
        //     if(snl[i] != 0) continue;

        //     if(sz(graph[v]) == 1) {
        //         que.push(i);
        //         snl[i] = snl[v];
        //         continue;
        //     }
            
        //     que.push(i);
        //     snl[i] = snl[v] + 1;
        // }
        for(int i = 0; i < sz(graph[v]); i++) {
            int temp = graph[v][i];
            if(snl[temp] != 0) continue;

            if(sz(graph[v]) == 1) {
                que.push(temp);
                snl[temp] = snl[v];
                continue;
            }

            que.push(temp);
            snl[i] = snl[v] +1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i < 101; i++) {
        for(int j = 1; j < 7; j++) {
            if(i + j > 100) break;
            graph[i].push_back(i + j);
        }
    }

    int head, tail;
    for(int i = 0; i < n; i++) {
        cin >> head >> tail;
        graph[head].clear();
        graph[head].push_back(tail);
    }

    for(int i = 0; i < m; i++) {
        cin >> head >> tail;
        graph[head].clear();
        graph[head].push_back(tail);
    }

    bfs();

    for(int i = 1; i < 101; i++) {
        cout << i << ' ' << snl[i] << '\n';
    }
}