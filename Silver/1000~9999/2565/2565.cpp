// 전깃줄 - Baekjoon Online Judge no.2565

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <fstream>

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
    vt<pii> arr;
    for(int i = 0; i < n; i++) {
        pii tmpp;
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tmpp = make_pair(tmp1, tmp2);
        arr.push_back(tmpp);
    }

    sort(all(arr));

    vt<int> dp(n, 1);
    int maxn = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i].sc > arr[j].sc) {
                dp[i] = max(dp[i], dp[j] + 1);
                maxn = max(maxn, dp[i]);
            }
        }
    }

    cout << n - maxn;
}