// 리모컨 - BOJ #1107

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

using namespace std;

vt<bool> buttons(10, true);
vt<int> goal;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, temp;
    cin >> n >> m;

    while(n) {
        goal.push_back(n % 10);
        n /= 10;
    }

    while(m--) {
        cin >> temp;
        buttons[temp] = false;
    }

    if(sz(goal) > 2) {
        
    }
}