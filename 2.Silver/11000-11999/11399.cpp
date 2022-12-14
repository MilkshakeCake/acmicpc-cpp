// ATM - BOJ #11399

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
    
    int n;
    cin >> n;
    vt<int> vec(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(all(vec));

    int sum = vec[0];

    for(int i = 1; i < n; i++) {
        vec[i] += vec[i -1];
        sum += vec[i];
    }

    cout << sum;
}