// 구간 합 구하기 5 - BOJ #11660

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
    
    vt<vt<int> > board;
    int n, m;
    int temp;
    cin >> n >> m;

    vt<int> v(n, 0);
    board.push_back(v);
    for(int i = 0; i < n; i++) {
        vt<int> tmp(n + 1, 0);
        for(int j = 1; j <= n; j++) {
            cin >> temp;
            tmp[j] = temp + tmp[j -1];
        }
        board.push_back(tmp);
    }

    while(m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for(int i = x1; i <= x2; i++) {
            sum += board[i][y2] - board[i][y1 - 1];
        }
        cout << sum << '\n';
    }
}