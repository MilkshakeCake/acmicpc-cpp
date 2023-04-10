// Parity Constraint Closest Pair - BOJ #

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

vt<int> arr;

int findMin(int mode) {
    int m = 1e9;

    for(int i = 0; i < (int)arr.size(); i++) {
        for(int j = 0; j < i; j++) {
            int temp = arr[i] - arr[j];
            if(temp % 2 != mode) continue;
            m = min(temp, m);
        }
    }

    return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
      
    int n;
    cin >> n;

    int input;
    bool flag = false;

    cin >> input;
    arr.push_back(input);

    for(int i = 1; i < n; i++) {
        cin >> input;
        int tmp = input - arr.back();
        arr.push_back(input);
        if(flag || tmp % 2 == 0) continue;
        flag = true;
    }

    int even = findMin(0);
    if(even == 1e9) even = -1;
    int odd = flag ? findMin(1) : -1;
    
    cout << even << ' ' << odd;
}