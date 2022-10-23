// 숫자 놀이 - Baekjoon Online Judge #12971

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
#include <sstream>
#include <map>

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
    
    int p1, p2, p3, x1, x2, x3;
    cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;
    
    int ret = -1;
    for(int n = 1; n <= p1 * p2 * p3; n++) {
        if(n % p1 == x1 && n % p2 == x2 && n % p3 == x3) {
            ret = n;
            break;
        }
    }
    cout << ret;
}