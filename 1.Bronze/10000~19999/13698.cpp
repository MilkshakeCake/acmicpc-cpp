// Hawk eyes - Baekjoon Online Judge #13698

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

    int small = 1;
    int large = 4;
    
    string input;
    cin >> input;
    for(auto& i : input) {
        if(i == 'A') {
            if(small == 1) small = 2;
            else if(small == 2) small = 1;

            if(large == 1) large = 2;
            else if(large == 2) large = 1;
        }
        
        if(i == 'B') {
            if(small == 1) small = 3;
            else if(small == 3) small = 1;

            if(large == 1) large = 3;
            else if(large == 3) large = 1;
        }
        
        if(i == 'C') {
            if(small == 1) small = 4;
            else if(small == 4) small = 1;

            if(large == 1) large = 4;
            else if(large == 4) large = 1;
        }
        
        if(i == 'D') {
            if(small == 3) small = 2;
            else if(small == 2) small = 3;

            if(large == 3) large = 2;
            else if(large == 2) large = 3;
        }
        
        if(i == 'E') {
            if(small == 4) small = 2;
            else if(small == 2) small = 4;

            if(large == 4) large = 2;
            else if(large == 2) large = 4;
        }
        
        if(i == 'F') {
            if(small == 3) small = 4;
            else if(small == 4) small = 3;

            if(large == 3) large = 4;
            else if(large == 4) large = 3;
        }
    }

    cout << small << '\n' << large;
}