// 숫자 놀이 - BOJ #12971

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