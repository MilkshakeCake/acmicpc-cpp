// 파일 합치기 - Baekjoon Online Judge no.11066

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

#define minLoc(v) min_element(all((v))) - (v).begin() 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        vt<int> book(n, 0);
        F_OR1(n) {
            cin >> book[i];
        }

        vt<vt<int> > dp(n, vt<int>(n, 0));
        dp[0][0] = book[0] + book[1];

        for(int i = 1; i < n -1; i++) {
            dp[0][i] = min(dp[0][i -1], book[i] + book[i +1]);
        }

        
    }
}