// "Project_Name" - Baekjoon Online Judge #

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vt<pii> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vt<vt<bool>> board(1002, vt<bool>(1002, true));
    vt<vt<vt<pii>>> graph;
    vt<vt<pii>> temp(1002);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char input;
            cin >> input;
            board[i][j] = input;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j]) {
                if(!board[i -1][j] && !board[i +1][j]) {
                    graph[i -1][j].push_back({i +1, j});
                    graph[i +1][j].push_back({i -1, j});
                }
                if(!board[i][j -1] && !board[i][j +1]) {
                    graph[i][j -1].push_back({i, j +1});
                    graph[i][j +1].push_back({i, j -1});
                }
            }
        }
    }
}