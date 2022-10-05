// 쿼드트리 - Baekjoon Online Judge #1992

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

bool board[65][65] = {};

void quadTree(int len, int x, int y) {
    if(len == 1) {
        cout << board[x][y];
        return;
    }

    bool flag = false;
    for(int i = x; i < x + len; i++) {
        for(int j = y; j < y + len; j++) {
            if(board[i][j] != board[x][y]) {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    if(!flag) {
        cout << board[x][y];
        return;
    }

    else {
        cout << '(';
        quadTree(len /2, x, y);
        quadTree(len /2, x, y + len /2);
        quadTree(len /2, x + len /2, y);
        quadTree(len /2, x + len /2, y + len /2);
        cout << ')';
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < n; j++) {
            board[i][j] = (bool)(temp[j] - 48);
        }
    }
    quadTree(n, 0, 0);
}