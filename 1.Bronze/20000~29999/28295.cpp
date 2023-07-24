// 체육은 코딩과목 입니다 - BOJ #28295

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
    
    int n = 0;
    for(int i = 0; i < 10; i++) {
        int temp;
        cin >> temp;
        n += temp;
        n %= 4;
    }

    if(n == 0) cout << 'N';
    else if(n == 1) cout << 'E';
    else if(n == 2) cout << 'S';
    else cout << 'W';
}