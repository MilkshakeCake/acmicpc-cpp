// 전깃줄 2 - BOJ #2565
// LIS(Longest Incremental Subsequence)

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

struct Line {
    int from, to;

    bool operator<(const Line &b) const { return from < b.from; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k;
    cin >> k;

    vt<Line> line(k);
    for(int i = 0; i < k; i++) {
        cin >> line[i].from >> line[i].to;
    }

    sort(all(line));

    for(int i = 0; i < k; i++) cout << line[i].to << ' ';
    cout << '\n';

    vt<int> dp(k, 1);
    vt<int> dptracker(k, 1);
    int maxn = 0;

    for(int i = 1; i < k; i++) {
        for(int j = 0; j < i; j++) {
            if(line[j].to < line[i].to) {
                if(dp[i] <= dp[j] +1) {
                    dp[i] = dp[j] +1;
                    dptracker[i] = j;
                }
                maxn = max(maxn, dp[i]);
            }
        }
    }

    

    printall(i, dptracker);

    cout << k - maxn;
}