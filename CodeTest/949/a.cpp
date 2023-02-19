// 2023년은 검은 토끼의 해 - BOJ #949-1
// 2023 ICPC Sinchon Winter Algorithm Camp Contest

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    if(n < 2023) {
        cout << 0;
        return 0;
    }

    int cnt = 0;
    for(int i = 2023; i <= n; i++) {
        int temp = i;
        while(temp % 10 != 3 && temp != 0) temp /= 10;
        if(temp < 202) continue;
        while(temp % 10 != 2 && temp != 0) temp /= 10;
        if(temp < 20) continue;
        while(temp % 10 != 0 && temp != 0) temp /= 10;
        if(temp < 20) continue;
        while(temp % 10 != 2 && temp != 0) temp /= 10;
        if(temp != 0) cnt++;
    }

    cout << cnt;
}