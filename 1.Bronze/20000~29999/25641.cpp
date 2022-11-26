// 균형 잡힌 소떡소떡 - Baekjoon Online Judge #25641

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
    int n;
    cin >> n;
    int s = 0;
    int t = 0;
    queue<bool> stst;
    char temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(temp == 's') {
            stst.push(true);
            s++;
        }

        else {
            stst.push(false);
            t++;
        }
    }

    while(s != t) {
        stst.front() ? s-- : t--;
        stst.pop();
    }

    int size = (int)stst.size();

    for(int i = 0; i < size; i++) {
        if(stst.front()) cout << 's';
        else cout << 't';
        stst.pop();
    }
}