// 해시 해킹 - BOJ #26008
// BOJ Contest 884 - 홍익대학교 PS 동아리 HI-ARC 2022

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