// 계단 오르기 - BOJ #2579

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

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define EACH(x, a) for (auto& x : a)

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[300] = {0};
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int dp[300];
    dp[0] = arr[0];
    dp[1] = arr[1] + arr[0];
    dp[2] = arr[2] + max(arr[1], arr[0]);
    for(int i = 3; i < n; i++) {
        dp[i] = arr[i] + max(arr[i-1] + dp[i-3], dp[i-2]);
    }

    cout << dp[n-1];
}