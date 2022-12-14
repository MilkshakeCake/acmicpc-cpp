// 펠린드롬 소떡소떡 - BOJ #25630

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    char stst[101];

    char temp;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        stst[i] = temp;
    }

    int cnt = 0;

    for(int i = 1; i <= n /2; i++) {
        if(stst[i] != stst[n - i +1]) {
            cnt++;
        }
    }
    cout << cnt;
}