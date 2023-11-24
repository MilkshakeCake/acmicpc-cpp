// 쓰윽~빡! 빠악~쓱! - BOJ #28470

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vt<double> a(100001, 0);
    vt<double> b(100001, 0);
    vt<double> k(100001, 0);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> k[i];

    ll sum = 0;

    for(int i = 0; i < n; i++) {
        if(k[i] >= 1) sum += floor<ll>(a[i]*k[i]) - b[i];
        else sum += a[i] - floor<ll>(b[i]*k[i]);
    }

    cout << sum;
}