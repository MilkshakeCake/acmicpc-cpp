// 부분합 - BOJ #1806

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
    
    int n, s; cin >> n >> s;
    vt<int> nums(1, 0);

    int start = 0;
    int end = 1;
    int len = 1e6 +1;

    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp + nums.back());
        if(temp > s) {
            cout << 1;
            return 0;
        }
    }

    if(nums.back() < s) {
        cout << 0;
        return 0;
    }

    while(start <= end && end <= n) {
        if(nums[end] - nums[start] < s) {
            end++;
        }
        else if(nums[end] - nums[start] >= s) {
            start++;
            len = min(len, end - start +1);
            if(start > end) end = start;
        }
    }

    cout << len;
}