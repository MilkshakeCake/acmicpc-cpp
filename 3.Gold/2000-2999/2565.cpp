// 전깃줄 - BOJ #2565

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