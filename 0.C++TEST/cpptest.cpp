// Practice Techniques of C++

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
    
    int n, m;
    cin >> n >> m;
    vt<vt<bool>> board(n, vt<bool>(m));
    
    pii point = {-1, -1};

    char input;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> input;
            if(input == '.') {
                if(point.first != -1) {
                    int avg = j - point.first;
                    point = {point.first + avg, point.second + avg};
                    cout << avg << '\n';
                }
                continue;
            }

            if(point.first == -1) point = {i, j};
        }
    }
}