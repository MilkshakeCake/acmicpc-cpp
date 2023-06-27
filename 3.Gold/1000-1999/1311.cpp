// 할 일 정하기 1 - BOJ #1311

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

int work[20][20];
int dp[3000000];                // approx 2^20

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vt<int> v[20];

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> work[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        v[0].push_back(1 << i);
        dp[1 << i] = work[0][i];
    }

    for(int cur = 1; cur < n; cur++) {
        vt<int> bits = v[cur -1];
        for(int i = 0; i < bits.size(); i++) {
            int curb = bits[i];
            for(int j = 0; j < n; j++) {
                int cost = work[cur][j];
                int next = curb | (1 << j);
                
                if(curb == next) continue;

                if(dp[next] > dp[curb] + cost || !dp[next]) {
                    dp[next] = dp[curb] + cost;
                    v[cur].push_back(next);
                }
            }
        }
    }

    cout << dp[(1 << n) -1] << endl;

    return 0;
}