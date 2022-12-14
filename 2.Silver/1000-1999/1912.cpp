// 연속합 - BOJ #1912

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
#define vtend(v) (v)[sz(v)-1]

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int arr[100000] = {0};
    int dp[100000] = {0};
    F_OR1(n) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    int res = dp[0];
    F_OR3(i, 1, n) {
        if(dp[i-1] >= 0) dp[i] = dp[i-1] + arr[i];
        else dp[i] = arr[i];
        res = max(res, dp[i]);
    }
    cout << res;
}