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
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        priority_queue<pair<int, int>> pq;
        int a, b;
        for(int i = 1; i <= n; i++) {
            cin >> a >> b;
            if(a > 10) continue;

            pq.push({b, i});
        }

        cout << pq.top().second << '\n';
    }
}