// 충남대학교 SW_IT Contest G

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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;


    string under;
    string newblock;
    cin >> under;
    bool flag = true;

    for(int i = 1; i < n; i++) {
        flag = false;
        cin >> newblock;
        for(int j = 1; j < m *2; j++) {
            if(j < m) {
                if(under.substr(0, j - 1) == newblock.substr(m - j, m - 1)) {
                    flag = true;
                    under = newblock;
                    break;
                }
            }
            else if(j == m) {
                if(newblock == under) {
                    flag = true;
                    under = newblock;
                    break;
                }
            }
            else {
                if(under.substr(j - m, m - 1) == newblock.substr(0, m *2 - j)) {
                    flag = true;
                    under = newblock;
                    break;
                }
            }
        }
        if(flag == false) break;
    }

    if(flag) cout << 1;
    else cout << 0;
}