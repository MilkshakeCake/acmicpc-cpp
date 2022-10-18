// Practice Techniques of C++

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

int board[30][30];
vt<vt<vt<pii>>> graph;

void init() {
    vt<vt<pii>> temp(30, vt<pii>(0));
    for(int i = 0; i < 30; i++) graph.push_back(temp);
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

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k < sz(graph[i][j]); k++) {
                cout << '(' << graph[i][j][k].fr << ',' << graph[i][j][k].sc << ") ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
}