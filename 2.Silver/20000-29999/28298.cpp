// ´õ ÈçÇÑ Å¸ÀÏ »öÄ¥ ¹®Á¦ - BOJ #28298

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

int diff(string a, string b) {
    int sum = 0;
    for(int i = 0; i < (int)a.length(); i++) {
        if(a[i] != b[i]) sum++;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> color(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> color[i][j];
        }
    }

    map<string, int> tile;
    vector<string> tiles;

    for(int i = 0; i < n; i += k) {
        for(int j = 0; j < m; j += k) {
            string now;
            for(int a = i; a < i + k; a++) {
                for(int b = j; b < j + k; b++) {
                    now += color[a][b];
                }
            }
            tiles.push_back(now);
            tile[now]++;
        }
    }

    auto pr = max_element(all(tile), [](const auto &x, const auto &y) {
        if(x.second == y.second) return x.first > y.first;
        return x.second < y.second;
    });

    int sum = 0;
    for(int i = 0; i < (int)tiles.size(); i++) {
        sum += diff(pr->first, tiles[i]);
    }

    cout << sum << '\n';

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j += k) {
            for(int a = 0; a < k; a++) {
                cout << pr->first[a + (i % k) * k];
            }
        }
        cout << '\n';
    }
}