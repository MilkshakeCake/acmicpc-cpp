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
        ull c, sum(0);
        cin >> n >> c;

        ull input;
        vt<ull> pictures;
        for(int i = 0; i < n; i++) {
            cin >> input;
            pictures.push_back(input);
            sum += input;
            c -= input * input;
        }

        c /= 4 * n;
        sum /= 2 * n;

        ull w = sqrtl(sum * sum + c);
        w -= sum;
        cout << w << '\n';
    }
}