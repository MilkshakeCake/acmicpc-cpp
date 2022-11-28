// 전깃줄 - BOJ #2565

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
    
    int k;
    cin >> k;

    vt<pii> line(k);
    for(int i = 0; i < k; i++) {
        cin >> line[i].first;
        cin >> line[i].second;
    }

    sort(all(line));

    vt<int> dp(k, 1);
    int maxn = 0;

    for(int i = 1; i < k; i++) {
        for(int j = 0; j < i; j++) {
            if(line[j].sc < line[i].sc) {
                dp[i] = max(dp[i], dp[j] +1);
                maxn = max(maxn, dp[i]);
            }
        }
    }

    cout << k - maxn;
}