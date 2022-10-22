// 나무 자르기 - Baekjoon Online Judge #2805

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <fstream>
#include <sstream>
#include <map>

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)

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