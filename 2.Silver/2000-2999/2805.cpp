// 나무 자르기 - BOJ #2805

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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vt<int> tree(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    sort(all(tree));

    ll high = 1000000001;
    ll low = 0;
    ll result = 0;

    while(low <= high) {
        ll mid = (high + low) / 2;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            mid <= tree[i] ? sum += tree[i] - mid : sum += 0;
        }

        if(sum < m) high = mid -1;
        else {
            low = mid + 1;
            result = max(result, mid);
        }
    }

    cout << result;
}