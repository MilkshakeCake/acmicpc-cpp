// 팩토리얼 0의 개수 - BOJ #1676

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
    
    int n, sum(0);
    cin >> n;
    int i = 1;
    while(n / pow(5, i)) {
        sum += n / pow(5, i);
        i++;
    }

    cout << sum;
}