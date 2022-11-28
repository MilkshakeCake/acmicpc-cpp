// 행렬 곱셈 순서 - BOJ #11049

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

#define INF INT32_MAX

using namespace std;

ll matrices[502];
vt<ll> pmul(502, 1);
vt<vt<ll>> dp(502, vt<ll>(502, -1));
ll n;

ll cut(int l, int r) {
    return matrices[l] * matrices[r +1];
}

ll dynamo(int l, int r) {
    ll& lr = dp[l][r];
    if(lr != -1) return lr;
    else if(l == r) {
        return 0;
    };

    lr = INF;

    for(int i = l; i < r; i++) {
        lr = min(lr, (cut(l, i) * cut(i +1, r) / matrices[i +1]) + dynamo(l, i) + dynamo(i +1, r));
    }

    return lr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    cin >> matrices[0] >> matrices[1];
    pmul[0] = matrices[0] * matrices[1];

    for(int i = 1; i < n; i++) {
        cin >> matrices[i] >> matrices[i +1];
        pmul[i] = pmul[i -1] * matrices[i +1];
    }

    cout << dynamo(0, n -1);
}