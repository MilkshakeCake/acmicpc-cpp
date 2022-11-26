// 조합 0의 개수 - Baekjoon Online Judge #2004

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    ll i = 5;
    ll sum5 = 0;

    while(n / i) {
        sum5 += (n / i);
        i *= 5;
    }

    i = 5;
    ll sub = n - m;
    while(sub / i) {
        sum5 -= (sub / i);
        i *= 5;
    }

    i = 5;
    while(m / i) {
        sum5 -= (m / i);
        i *= 5;
    }

    ll sum2 = 0;

    i = 2;
    while(n / i) {
        sum2 += (n / i);
        i *= 2;
    }

    i = 2;
    while(sub / i) {
        sum2 -= (sub / i);
        i *= 2;
    }

    i = 2;
    while(m / i) {
        sum2 -= (m / i);
        i *= 2;
    }

    cout << min(sum2, sum5);
}