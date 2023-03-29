// 특식 배부 - BOJ #27110

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

    int n, a, b, c, sum(0);
    cin >> n >> a >> b >> c;

    sum += (a > n ? n : a);
    sum += (b > n ? n : b);
    sum += (c > n ? n : c);

    cout << sum;
}