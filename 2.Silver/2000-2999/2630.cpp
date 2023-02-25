// 색종이 만들기 - BOJ #2630

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

bool board[129][129] = {};
int blue = 0;
int white = 0;

void dnc(int len, int x, int y) {
    if(len == 1) {
        board[x][y] ? blue++ : white++;
        return;
    }

    bool flag = true;
    for(int i = x; i < x + len; i++) {
        for(int j = y; j < y + len; j++) {
            if(board[i][j] != board[x][y]) {
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }

    if(flag) {
        board[x][y] ? blue++ : white++;
    }

    else {
        dnc(len /2, x, y);
        dnc(len /2, x + len /2, y);
        dnc(len /2, x, y + len /2);
        dnc(len /2, x + len /2, y + len /2);
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
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    dnc(n, 0, 0);
    cout << white << '\n' << blue;
}