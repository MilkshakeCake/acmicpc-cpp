// 이항 계수 3 - Baekjoon Online Judge #11401

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

int main() {
    ll n, k;
    cin >> n >> k;

    ll result = 1;
    for(int i = n - k + 1; i <= n; i++) {
        result *= i;
        result %= MOD;
    }

    ll kfac = 1;
    for(int i = 1; i <= k; i++) {
        kfac *= i;
        kfac %= MOD;
    }

    ll ret = 1;
	ll goal = MOD -2;
	while(goal){
		if(goal % 2) {
			ret *= kfac;
			ret %= MOD;
		}
		kfac *= kfac;
		kfac %= MOD;
		goal /= 2;
	}
    ret %= MOD;

    cout << (result * ret) % MOD;
}