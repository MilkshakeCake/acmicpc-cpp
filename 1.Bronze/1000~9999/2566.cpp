// 최댓값 - BOJ #2566

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
    
    int row, col, maxn(-1), input;
    
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            cin >> input;
            if(input > maxn) {
                row = i;
                col = j;
                maxn = input;
            }
        }
    }

    cout << maxn << '\n' << row << ' ' << col;
}