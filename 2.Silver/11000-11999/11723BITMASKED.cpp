// С§Че - BOJ #11723
// Bitmasked Version

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define pll pair<long, long>
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
    
    int m;
    cin >> m;
    int set(0), x(0);
    string order;
    while(m--) {
        cin >> order;
        if(order == "add") {
            cin >> x;
            set |= (1 << x);
        }
        else if(order == "remove") {
            cin >> x;
            set &= ~(1 << x);
        }
        
        else if(order == "check") {
            cin >> x;
            cout << (bool)(set & (1 << x)) << '\n';
        }
        
        else if(order == "toggle") {
            cin >> x;
            set ^= (1 << x);
        }
        
        else if(order == "all") {
            set = ~(1 << 21);
        }
        
        else if(order == "empty") {
            set = 0;
        }
    }
}