// 평범한 배낭 - BOJ #12865

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vt<vt<int>> board(n +1, vt<int>(k +1, 0));
    vt<pii> obj(n +1, {0, 0});

    for(int i = 1; i <= n; i++) cin >> obj[i].fr >> obj[i].sc;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j < obj[i].fr) board[i][j] = board[i -1][j];
            else {
                board[i][j] = max(board[i -1][j], board[i-1][max(0, j - obj[i].fr)] + obj[i].sc);
            }
        }
    }

    cout << board[n][k];
}