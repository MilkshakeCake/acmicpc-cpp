// lcs 2 - Baekjoon Online Judge no.9251

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
#define printall(i, a) for(auto &i : a) cout << i << ' '

using namespace std;

int dp[1001][1001] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string a = "";
    string b = "";
    cin >> a >> b;

    if(sz(a) == 1 || sz(b) == 1) {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < sz(a); i++) {
        for(int j = 0; j < sz(b); j++) {
            if(a[i] == b[j]) dp[i +1][j +1] = dp[i][j] + 1;
            
            else dp[i +1][j +1] = max(dp[i][j +1], dp[i +1][j]);
        }
    }

    int track1 = sz(a); 
    int track2 = sz(b);
    stack<char> lcs;

    while(track1 > 0 && track2 > 0) {
        if(dp[track1][track2] == dp[track1 -1][track2]) track1--;
        else if(dp[track1][track2] == dp[track1][track2 -1]) track2--;
        else {
            lcs.push(a[track1 -1]);
            track1--;
            track2--;
        }
    }

    cout << dp[sz(a)][sz(b)] << '\n';
    while(!lcs.empty()) {
        cout << lcs.top();
        lcs.pop();
    }
}