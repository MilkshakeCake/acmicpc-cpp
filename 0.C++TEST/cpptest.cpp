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
    
    int n, tmp;
    cin >> n >> tmp;

    vt<int> arr;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(all(arr));
    printall(i, arr);
}