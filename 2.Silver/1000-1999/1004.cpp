// 어린 왕자 - BOJ #1004

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