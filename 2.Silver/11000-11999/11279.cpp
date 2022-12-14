// 최대 힙 - BOJ #11279

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue<int> heap;

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