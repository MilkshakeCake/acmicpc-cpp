// 구간 합 구하기 - BOJ #11659

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
    
    int n, m;
    cin >> n >> m;
    
    vt<int> arr(1, 0);
    
    F_OR1(n) {
        int temp;
        cin >> temp;
        arr.push_back(temp + arr[sz(arr)-1]);
    }

    while(m--) {
        int start, fin;
        cin >> start >> fin;
        cout << arr[fin] - arr[start - 1] << '\n';
    }
}