// 발머의 피크 이론 - BOJ #949-3

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
    
    int n, l, cnt(0);
    cin >> n >> l;
    vt<int> alc(10000001, 0);
    vt<int> con(10000001, 0);
    for(int i = 0; i < n; i++) {
        cin >> alc[i];
    }

    con[0] = alc[0];
    for(int i = 1; i < l && i < n; i++) {
        con[i] = con[i -1];
        con[i] += alc[i];
    }

    con[l] = con[l -1] - alc[0] + alc[l];

    for(int i = l +1; i < n; i++) {
        con[i] = con[i -1] - alc[i - l] + alc[i];
    }

    for(int i = 0; i < n; i++) if(con[i] >= 129 && con[i] <= 138) cnt++;

    for(int i = 0; i < n + l; i++) cout << con[i] << ' ';

    cout << cnt;
    return 0;
}