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
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        if(n == 1) {
            cin >> k;
            cout << 0 << '\n';
            continue;
        }

        int tmp;
        vector<int> round;

        for(int i = 0; i < n; i++) {
            cin >> tmp;
            round.push_back(tmp);
        }

        sort(all(round));

        vt<int> parse;

        for(int i = 1; i < n; i++) {
            parse.push_back(round[i] - round[i -1]);
        }

        vt<int> dp(n -1, 1);
        int lss = 1;

        if(parse[0] <= k) dp[0] = 2;
        lss = max(dp[0], lss);

        for(int i = 1; i < (int)parse.size(); i++) {
            if(parse[i] <= k) dp[i] = dp[i -1] + 1;
            lss = max(lss, dp[i]);
        }

        cout << n - lss << '\n';
    }
}