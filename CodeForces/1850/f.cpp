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

        map<int, int> frog;
        vt<int> road(n +1, 0);
        int tmp;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            frog[tmp]++;
        }

        int trap = 0;

        for(int i = 1; i <= n; i++) {
            int now = i;
            while(now <= n) {
                road[now] += frog[i];
                now += i;
            }
            trap = max(trap, road[i]);
        }

        cout << trap << '\n';
    }
}