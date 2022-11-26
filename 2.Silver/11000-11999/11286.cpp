// 절댓값 힙 - Baekjoon Online Judge #11286

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

template<typename _Tp>
    struct compare : public binary_function<_Tp, _Tp, bool>
    {
      _GLIBCXX14_CONSTEXPR
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      {
        if(abs(__x) != abs(__y)) return abs(__x) > abs(__y);
        return __x > __y;
      }
    };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue<int, vt<int>, compare<int>> heap;

    int n;
    cin >> n;

    int input;
    while(n--) {
        cin >> input;
        if(input) {
            heap.push(input);
        }

        else {
            if(heap.empty()) {
                cout << "0\n";
                continue;
            }
            cout << heap.top() << '\n';
            heap.pop();
        }
    }
}