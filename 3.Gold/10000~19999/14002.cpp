// 가장 긴 증가하는 부분 수열 4 - Baekjoon Online Judge #14002

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
    
    int n, temp;
    cin >> n;

    vt<int> sequence(1, 0);
    vt<int> dp(1001, 1);
    int tracker[1001] = {0};

    for(int i = 0; i < n; i++) {
        cin >> temp;
        sequence.push_back(temp);
    }

    int maxn = 0;
    int idx = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(sequence[i] > sequence[j]) {
                if(dp[i] < dp[j] +1) {
                    dp[i] = dp[j] +1;
                    tracker[i] = j;
                }
            }
        }
        if(dp[i] > maxn) {
            maxn = dp[i];
            idx = i;
        }
    }

    stack<int> output;
    output.push(sequence[idx]);
    while(tracker[idx]) {
        output.push(sequence[tracker[idx]]);
        idx = tracker[idx];
    }

    cout << maxn << '\n';
    while(!output.empty()) {
        cout << output.top() << ' ';
        output.pop();
    }
}