// "Project_Name" - BOJ #

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
#define endl '\n'

using namespace std;

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<bool> isP(n +1, false);
    for (int i = 2; i * i <= n; i++) {
        if (!isP[i]) {
            for (int j = i * i; j <= n; j += i) {
                isP[j] = true;
            }
        }
    }

    
}