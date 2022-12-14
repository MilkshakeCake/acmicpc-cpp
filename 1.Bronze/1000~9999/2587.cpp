// 대표값2 - BOJ #2587

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
    
    int temp, sum = 0;
    vt<int> num;
    for(int i = 0; i < 5; i++) {
        cin >> temp;
        num.push_back(temp);
        sum += temp;
    }

    sort(all(num));
    cout << sum / 5 << '\n' << num[2];
}