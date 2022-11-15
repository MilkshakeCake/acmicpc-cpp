// 두 수의 합 - Baekjoon Online Judge #3273

#include <bits/stdc++.h>

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
    
    int n, temp;
    cin >> n;
    vt<int> arr;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    int x; cin >> x;

    sort(all(arr));

    int sidx(0), eidx(n -1), cnt(0);

    while(sidx < eidx) {
        if(arr[sidx] + arr[eidx] == x) {
            cnt++;
            eidx--;
        }
        else (arr[sidx] + arr[eidx] > x) ? eidx-- : sidx++;
    }

    cout << cnt;
}