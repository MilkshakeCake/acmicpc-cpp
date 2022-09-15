// "Project_Name" - Baekjoon Online Judge no."Project_Num"

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define vtend(v) (v)[sz(v)-1]

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