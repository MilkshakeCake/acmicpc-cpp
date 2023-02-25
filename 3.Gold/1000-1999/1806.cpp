// 부분합 - BOJ #1806

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