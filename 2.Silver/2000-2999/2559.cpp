// 수열 - BOJ #2559

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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    int maxn = -10000000;
    int temp = 0;
    vt<int> arr(1, 0);
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    for(int i = 1; i <= k; i++) {
        temp += arr[i];
    }
    maxn = max(maxn, temp);

    for(int i = 2; i < n - k + 2; i++) {
        temp -= arr[i -1];
        temp += arr[i + k -1];
        maxn = max(maxn, temp);
    }
    cout << maxn;
}