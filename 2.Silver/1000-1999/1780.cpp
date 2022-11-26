// 종이의 개수 - Baekjoon Online Judge #1780

#include <bits/stdc++.h>
#include <map>

#define uint unsigned int
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

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)

using namespace std;

map<int, int> nums;
int board[3000][3000];

void paper(int len, int x, int y) {
    if(len == 1) {
        nums[board[x][y]]++;
        return;
    }

    bool flag = true;
    for(int i = 0; i < len * len; i++) {
        if(board[x][y] != board[x + i /len][y + i %len]) {
            flag = false;
            break;
        }
    }

    if(flag) {
        nums[board[x][y]]++;
    }

    else {
        for(int j = 0; j < 9; j++) {
            paper(len /3, x + (j /3) * (len /3), y + (j %3) * (len /3));
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    for(int i = 0; i < n * n; i++) {
        cin >> board[i / n][i % n];
    }

    paper(n, 0, 0);

    cout << nums[-1] << '\n' << nums[0] << '\n' << nums[1];
}