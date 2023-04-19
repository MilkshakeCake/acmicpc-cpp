// 네모네모 시력검사 - BOJ #18242

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vt<vt<bool>> board(101, vt<bool>(101, false));
    
    pii point = {-1, -1};

    char input;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> input;
            input == '.' ? board[i][j] = false : board[i][j] = true;

            if(input == '.') continue;
            if(point.first == -1) {
                point = {i, j};
            }
        }
    }

    int len = 1;
    while(board[point.first][point.second + len]) len++;
    while(board[point.first + len][point.second]) len++;

    len--;

    if(!board[point.first][point.second + len /2]) cout << "UP";
    if(!board[point.first + len][point.second + len /2]) cout << "DOWN";
    if(!board[point.first + len /2][point.second]) cout << "LEFT";
    if(!board[point.first + len /2][point.second + len]) cout << "RIGHT";
}