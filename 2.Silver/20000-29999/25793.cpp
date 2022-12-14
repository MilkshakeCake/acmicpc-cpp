// 초콜릿 피라미드 - BOJ #25793

#include <bits/stdc++.h>
#include <inttypes.h>

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        ll R, C;
        cin >> R >> C;
        ll N = min(R, C);
        ll M = max(R, C) - N;

        ll white = (N * (N * N *2 +1)) / 3 + N * N * M;
        ll dark = (N * (N * N -1)) * 2 / 3 + N * N * M;

        cout << white << ' ' << dark << '\n';
    }
}