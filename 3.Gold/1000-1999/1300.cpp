// K번째 수 - BOJ #1300

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

ll n, k;

int main() {
    cin >> n >> k;

    ll smol = 0;
    ll big = n * n;

    ll result = 1;

    while(smol <= big) {
        ll mid = (smol + big) /2;

        ll idx = 0;

        for(ll i = 1; i <= n; i++) {
            idx += min(n, mid / i);
        }

        if(idx >= k) {
            result = mid;
            big = mid -1;
        }
        else smol = mid +1;
    }

    cout << result;
}