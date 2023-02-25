// 집합 - BOJ #11723

#include <string>
#include <iostream>
#include <algorithm>

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