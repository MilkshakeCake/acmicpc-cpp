// 두 수의 합 - BOJ #3273

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

    int start(0), end(n -1), cnt(0);

    while(start < end) {
        if(arr[start] + arr[end] == x) {
            cnt++;
            end--;
        }
        else (arr[start] + arr[end] > x) ? end-- : start++;
    }

    cout << cnt;
}