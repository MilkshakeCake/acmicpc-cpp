// 적록색약 - Baekjoon Online Judge #10026

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

vt<vt<int>> Colorblind(102, vt<int>(102, -1));
vt<vt<int>> FHD(102, vt<int>(102, -1));

vt<vt<bool>> visited(102, vt<bool>(102, false));

const vt<pii> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int N;

void init() {
    for(int i = 0; i < 102; i++) {
        for(int j = 0; j < 102; j++) {
            visited[i][j] = false;
        }
    }
}

void dfs(int x, int y, vt<vt<int>>& board) {
    if(visited[x][y]) return;
    visited[x][y] = true;

    for(auto& i : moves) {
        int nx = x + i.fr;
        int ny = y + i.sc;
        if(board[nx][ny] != -1 && board[nx][ny] == board[x][y]) {
            dfs(nx, ny, board);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            char input;
            cin >> input;
            if(input == 'R') {
                Colorblind[i][j] = 1;
                FHD[i][j] = 1;
            }
            if(input == 'G') {
                Colorblind[i][j] = 1;
                FHD[i][j] = 2;
            }
            if(input == 'B') {
                Colorblind[i][j] = 2;
                FHD[i][j] = 3;
            }
        }
    }

    int cbcnt = 0;
    int fhdcnt = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(!visited[i][j]) {
                cbcnt++;
                dfs(i, j, Colorblind);
            }
        }
    }

    init();

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(!visited[i][j]) {
                fhdcnt++;
                dfs(i, j, FHD);
            }
        }
    }

    cout << fhdcnt << ' ' << cbcnt;
}