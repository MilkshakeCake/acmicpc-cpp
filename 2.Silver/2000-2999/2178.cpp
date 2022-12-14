// 미로 탐색 - BOJ #2178

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

vt<vt<vt<pii>>> labyrinth;
queue<pii> que;
bool field[101][101] = {false, };
int visited[101][101] = {0, };

void init() {
    vt<vt<pii>> temp(101, vt<pii>(0));
    for(int i = 0; i < 101; i++) labyrinth.push_back(temp);
}

void bfs(int x, int y) {
    visited[x][y] = 1;
    que.push(make_pair(x, y));

    while(!que.empty()) {
        pii v = que.front();
        que.pop();

        for(int i = 0; i < sz(labyrinth[v.fr][v.sc]); i++) {
            pii temp = labyrinth[v.fr][v.sc][i];
            if(!visited[temp.fr][temp.sc]) {
                que.push(temp);
                visited[temp.fr][temp.sc] = visited[v.fr][v.sc] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    init();

    for(int i = 1; i <= n; i++) {
        string input;
        cin >> input;
        for(int j = 1; j <= m; j++) {
            int temp = (int)input[j -1] - 48;
            field[i][j] = temp;
            if(temp) {
                if(field[i][j -1]) {
                    labyrinth[i][j].push_back(make_pair(i, j -1));
                    labyrinth[i][j -1].push_back(make_pair(i, j));
                }

                if(field[i -1][j]) {
                    labyrinth[i][j].push_back(make_pair(i -1, j));
                    labyrinth[i -1][j].push_back(make_pair(i, j));
                }
            }
        }
    }

    bfs(1, 1);

    cout << visited[n][m];
}