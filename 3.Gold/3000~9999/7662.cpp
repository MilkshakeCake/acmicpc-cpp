// 이중 우선순위 큐 - BOJ #7662
// Dual Priority Queue

//입력
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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    while(T--) {
        int k, num;
        char input;
        multiset<int> ms;

        cin >> k;
        while(k--) {
            cin >> input >> num;
            if(input == 'I') ms.insert(num);
            else if(!ms.empty()) {
                if(num == 1) {
                    ms.erase(--ms.end());
                }
                else {
                    ms.erase(ms.begin());
                }
            }
        }
        if(ms.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }
}