// 꿀 아르바이트 - BOJ #12847(2nd approach)

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
    
	ll n, m;
	cin >> n >> m;
	ll arr[100001];

	ll ans, tmp = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for(int i = 0; i < m; i++) {
		tmp += arr[i];
	}
	ans = tmp;

	for(int i = 0; i < n - m; i++) {
		tmp += arr[i + m];
		tmp -= arr[i];
		ans = max(ans, tmp);
	}

	cout << ans;
}