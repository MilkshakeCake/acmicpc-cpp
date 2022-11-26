// 해시 해킹 - Baekjoon Online Judge #26008
// BOJ Contest 884 - 홍익대학교 PS 동아리 HI-ARC 2022

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

#define MOD 1000000007

using namespace std;

ll power(ll a, ll n) {
    ll result = 1;
    while(n) {
        if(n % 2) {
            result *= a;
            result %= MOD;
        }
        a *= a;
        a %= MOD;
        n /= 2;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, M, A, H;
    cin >> N >> M >> A >> H;

    cout << power(M, N-1) % MOD;
}