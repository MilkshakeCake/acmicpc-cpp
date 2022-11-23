// 집합 - Baekjoon Online Judge #11723

#include <string>
#include <iostream>
#include <algorithm>

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

    bool set[21] = {false};
    
    int m;
    cin >> m;
    while(m--) {
        int x;
        string input;
        cin >> input;
        if(input == "add") {
            cin >> x;
            set[x] = true;
            continue;
        }
        
        if(input == "remove") {
            cin >> x;
            set[x] = false;
            continue;
        }
        
        if(input == "check") {
            cin >> x;
            cout << set[x] << '\n';
            continue;
        }
        
        if(input == "toggle") {
            cin >> x;
            set[x] = !set[x];
            continue;
        }
        
        if(input == "all") {
            for(int i = 1; i < 21; i++) {
                set[i] = true;
            }
            continue;
        }
        
        if(input == "empty") {
            for(int i = 1; i < 21; i++) {
                set[i] = false;
            }
            continue;
        }
    }
}