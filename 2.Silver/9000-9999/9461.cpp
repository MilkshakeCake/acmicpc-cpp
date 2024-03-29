// 파도반 수열 - BOJ #9461

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

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define EACH(x, a) for (auto& x : a)

using namespace std;

ll len[101] = {0};

ll pn(int n) {
    if(len[n]) return len[n];
    else {
        len[n] = pn(n-1) + pn(n-5);
    }
    return len[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    int n;
    len[0] = 0;
    len[1] = 1;
    len[2] = 1;
    len[3] = 1;
    len[4] = 2;
    len[5] = 2;
    for(int i = 0; i < t; i++) {
        cin >> n;
        cout << pn(n) << '\n';
    }
}