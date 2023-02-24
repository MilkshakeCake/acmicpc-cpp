// 조합 0의 개수 - BOJ #2004

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << ' '

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