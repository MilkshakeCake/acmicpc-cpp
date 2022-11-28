// 플로이드 2 - Baekjoon Online Judge #11780

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

vt<vt<ll>> matrix(101, vt<ll>(101, INF));
vt<vt<ll>> tracker(101, vt<ll>(101, 0));
vt<int> V;

void findPath(int Start, int End)
{
    if (tracker[Start][End] == 0)
    {
        V.push_back(Start);
        V.push_back(End);
        return;
    }
    findPath(Start, tracker[Start][End]);
    V.pop_back();
    findPath(tracker[Start][End], End);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    ll s, e, c;

    while(m--) {
        cin >> s >> e >> c;
        matrix[s][e] = min(matrix[s][e], c);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                if(matrix[i][j] > (matrix[i][k] + matrix[k][j])) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    tracker[i][j] = k;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << (matrix[i][j] == INF ? 0 : matrix[i][j]) << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] == INF) cout << 0;
            else {
                V.clear();
                findPath(i, j);
                cout << V.size() << " ";
                for (int k = 0; k < sz(V); k++) cout << V[k] << " ";
            }
            cout << endl;
        }
    }
}   