// 단지번호붙이기 - BOJ #2667

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

using namespace std;

int board[30][30];
vt<vt<vt<pii>>> graph;
bool visited[30][30] = {0, };
vt<int> result;
int save = 0;

void init() {
    vt<vt<pii>> temp(30, vt<pii>(0));
    for(int i = 0; i < 30; i++) graph.push_back(temp);
}

void dfs(int x, int y) {
    if(visited[x][y]) return;
    visited[x][y] = true;
    save++;

    for(int i = 0; i < sz(graph[x][y]); i++) {
        dfs(graph[x][y][i].fr, graph[x][y][i].sc);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    init();

    for(int i = 1; i <= n; i++) {   //board init
        for(int j = 1; j <= n; j++) {
            char input;
            cin >> input;
            int temp = (int)input -48;
            board[i][j] = temp;
            if(temp) {
                if(board[i -1][j]) {
                    graph[i][j].push_back(make_pair(i -1, j));
                    graph[i -1][j].push_back(make_pair(i, j));
                }

                if(board[i][j -1]) {
                    graph[i][j].push_back(make_pair(i, j -1));
                    graph[i][j -1].push_back(make_pair(i, j));
                }
            }
            sort(all(graph[i][j]));
        }
    }

    int groupcnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            
            if(!visited[i][j] && board[i][j]) {
                groupcnt++;
                dfs(i, j);
                result.push_back(save);
                save = 0;
            }
        }
    }

    cout << groupcnt << '\n';
    sort(all(result));
    EACH(i, result) cout << i << '\n';
}