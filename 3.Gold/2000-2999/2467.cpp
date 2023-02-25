// 용액 - BOJ #2467

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