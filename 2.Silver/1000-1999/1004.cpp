// 어린 왕자 - BOJ #1004

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

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)

using namespace std;

int sx, sy, fx, fy;
int sysx, sysy, rad;

int disPow(int& x, int& y) {
    return pow(x - sysx, 2) + pow(y - sysy, 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc; cin >> tc;
    while(tc--) {
        cin >> sx >> sy >> fx >> fy;

        int nos; cin >> nos;

        int cnt = 0;

        while(nos--) {
            cin >> sysx >> sysy >> rad;

            rad *= rad;

            int ds = disPow(sx, sy);
            int df = disPow(fx, fy);

            if(ds < rad || df < rad) (ds < rad && df < rad) ? cnt : cnt++;
        }

        cout << cnt << '\n';
    }
}