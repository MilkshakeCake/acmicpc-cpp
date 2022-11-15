// 두 용액 - Baekjoon Online Judge #2470

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
    
    int n, temp; cin >> n;
    vt<int> liquid;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        liquid.push_back(temp);
    }
    sort(all(liquid));

    int start(0), end(n -1);
    int alk(liquid[start]), acid(liquid[end]);
    int mix = INT32_MAX;
    while(start < end) {
        int sum = liquid[start] + liquid[end];
        if(abs(sum) < mix) {
            mix = abs(sum);
            alk = liquid[start];
            acid = liquid[end];

            if(sum == 0) break;
        }
        sum < 0 ? start++ : end--;
    }

    cout << alk << ' ' << acid;
}