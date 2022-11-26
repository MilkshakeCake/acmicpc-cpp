// 가운데를 말해요 - Baekjoon Online Judge #1655

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

    priority_queue<int, vt<int>, less<int>> maximal;
    priority_queue<int, vt<int>, greater<int>> minimal;

    int n;
    cin >> n;

    int temp;
    cin >> temp;
    maximal.push(temp);
    n--;

    cout << temp << '\n';

    while(n--) {
        cin >> temp;
        if(maximal.size() == minimal.size()) {
            maximal.push(temp);
        }

        else {
            minimal.push(temp);
        }
        
        if(maximal.top() > minimal.top()) {
            temp = maximal.top();
            maximal.pop();
            maximal.push(minimal.top());
            minimal.pop();
            minimal.push(temp);
        }

        cout << maximal.top() << '\n';
    }
}