// ´õ ÈçÇÑ Å¸ÀÏ »öÄ¥ ¹®Á¦ - BOJ #28298

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

int diff(string a, string b) {
    int sum = 0;
    for(int i = 0; i < (int)a.length(); i++) {
        if(a[i] != b[i]) sum++;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<int>>> tile(k, vector<vector<int>>(k, vector<int>(28, 0)));
    vector<vector<char>> board(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            tile[i % k][j % k][(int)board[i][j] - 65]++;
        }
    }

    int sum = 0;

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            for(int h = 0; h < 26; h++) {
                if(tile[i][j][26] >= tile[i][j][h]) continue;
                tile[i][j][26] = tile[i][j][h];
                tile[i][j][27] = h + 65;
            }
            sum += (n / k) * (m / k) - tile[i][j][26];
        }
    }

    cout << sum << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << (char)tile[i % k][j % k][27];
        }
        cout << '\n';
    }
}