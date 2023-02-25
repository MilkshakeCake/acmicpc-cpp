// 출제비 재분배 - BOJ #26145

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
    
    int n, m, temp;
    cin >> n >> m;
    vt<int> csuite(n + m, 0);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        csuite[i] = temp;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n + m; j++) {
            cin >> temp;
            csuite[i] -= temp;
            csuite[j] += temp;
        }
    }

    printall(i, csuite);
}