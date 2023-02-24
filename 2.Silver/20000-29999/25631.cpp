// 마트료시카 합치기 - BOJ #25631

#include <bits/stdc++.h>
#include <map>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
    
    map<int, int> mat;
    int n;
    cin >> n;
    int temp;
    int cnt = 1;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(mat[temp] != 0) {
            cnt = max(cnt, ++mat[temp]);
            continue;
        }
        mat[temp]++;
    }
    cout << cnt;
}