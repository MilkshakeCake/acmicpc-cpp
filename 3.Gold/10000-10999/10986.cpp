// 나머지 합 - BOJ #10986

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
    
    int n, mod;
    cin >> n >> mod;
    vt<int> arr(mod, 0);

    int temp;
    unsigned ll int sum = 0;
    unsigned ll int result = 0;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
        sum %= mod;
        result += arr[sum % mod]++;
    }
    cout << result + arr[0];
}