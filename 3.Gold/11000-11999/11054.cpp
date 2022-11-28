// 가장 긴 바이토닉 부분 수열 - Baekjoon Online Judge no.11054

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
    
    int n;
    cin >> n;

    vt<int> arr;
    int temp;
    F_OR1(n) {
        cin >> temp;
        arr.push_back(temp);
    }

    vt<int> dp(1001, 1);
    vt<int> rdp(1001, 1);

    //forward dp
    F_OR3(i, 0, n) {
        F_OR3(j, 0, i) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    //reverse dp
    for(int i = n -1; i >= 0; i--) {
        for(int j = n -1; j >= i; j--) {
            if(arr[j] < arr[i]) {
                rdp[i] = max(rdp[i], rdp[j]+1);
            }
        }
    }
    int end = 0;
    for(int i = 0; i < n; i++) {
        end = max(dp[i] + rdp[i] -1, end);
    }
    cout << end;
}