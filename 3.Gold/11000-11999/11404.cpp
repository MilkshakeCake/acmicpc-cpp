// 플로이드 - BOJ #11404
// Floyd-Warshall Algorithm

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

#define INF INT32_MAX

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vt<vt<ll>> matrix(101, vt<ll>(101, INF));
    
    ll a, b, c;
    while(m--) {
        cin >> a >> b >> c;
        matrix[a][b] = min(matrix[a][b], c);
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            if(i == k) matrix[i][k] = 0;
            for(int j = 1; j <= n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << (matrix[i][j] != INF ? matrix[i][j] : 0) << ' ';
        }
        cout << '\n';
    }
}