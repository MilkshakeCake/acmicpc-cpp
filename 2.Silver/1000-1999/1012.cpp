// 유기농 배추 - BOJ #1012

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

bool field[100][100];
vt<vt<vt<pii>>> graph;
bool visited[100][100];
int groupcnt = 0;

void init() {
    groupcnt = 0;
    graph.clear();
    vt<vt<pii>> temp(100, vt<pii>(0));
    for(int i = 0; i < 100; i++) {
        graph.push_back(temp);
        for(int j = 0; j < 100; j++) {
            visited[i][j] = false;
            field[i][j] = false;
        }
    }
}
    
void dfs(int x, int y) {
    if(visited[x][y]) return;

    visited[x][y] = true;

    for(int i = 0; i < sz(graph[x][y]); i++) {
        dfs(graph[x][y][i].fr, graph[x][y][i].sc);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, m, n, k;
    cin >> t;
    while(t--) {
        init();
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            a++; b++;
            field[a][b] = true;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(field[i][j]) {
                    if(field[i -1][j]) {
                        graph[i][j].push_back(make_pair(i -1, j));
                        graph[i -1][j].push_back(make_pair(i, j));
                    }

                    if(field[i][j -1]) {
                        graph[i][j].push_back(make_pair(i, j -1));
                        graph[i][j -1].push_back(make_pair(i, j));
                    }
                    sort(all(graph[i][j]));
                }
            }
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(!visited[i][j] && field[i][j]) {
                    groupcnt++;
                    dfs(i, j);
                }
            }
        }
        
        cout << groupcnt << '\n';
    }
}