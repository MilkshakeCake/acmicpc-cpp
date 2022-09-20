// 평범한 배낭 - Baekjoon Online Judge no.12865

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>

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

int board[101][100001] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vt<pii> arr(101);

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].fr >> arr[i].sc;
    }

    for(int i = arr[0].fr; i <= k; i++) {
        board[0][i] = arr[0].sc;
    }

    for(int i = 1; i < n; i++) {
        int w = arr[i].fr;
        int v = arr[i].sc;
        board[i][w-1] = v;

        for(int j = 1; j <= k; j++) {
            if(j < w) {
                board[i][j] = board[i-1][j];
            }
            else {
                board[i][j] = max(board[i-1][j], v + board[i-1][j - w]);
            }
        }
    }

    int result = 0;

    for(int i = 0; i < n; i++) {
        result = max(result, board[i][k]);
    }

    cout << result;
}