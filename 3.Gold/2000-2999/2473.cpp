// 세 용액 - BOJ #2473

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

struct ABS {
    int val;

    bool operator<(const ABS &b) const {
        return abs(val) < abs(b.val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, temp; cin >> n;
    vt<int> liquid;
    vt<ABS> liqABS;
    
    for(int i = 0; i < n; i++) {
        cin >> temp;
        liquid.push_back(temp);
        liqABS.push_back({temp});
    }
    sort(all(liquid));
    sort(all(liqABS));

    int start(0), end(n -1), alk(liquid[start]), acid(liquid[end]), mix(INT32_MAX), set(liqABS[0].val);
    for(auto &i : liqABS) {
        while(start < end) {
            int sum = liquid[start] + liquid[end];
            if(abs(sum) < mix) {
                mix = abs(sum);
                if(liquid[start] != i.val) alk = liquid[start];
                if(liquid[end] != i.val) acid = liquid[end];

                if(sum + i.val == 0) {
                    set = i.val;
                    break;
                }
            }
            sum + i.val < 0 ? start++ : end--;
        }
    }
    
    vt<int> arr;
    arr.push_back(alk);
    arr.push_back(acid);
    arr.push_back(set);

    sort(all(arr), greater<>());
    printall(i, arr);
}