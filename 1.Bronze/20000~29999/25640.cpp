// MBTI - BOJ #25640

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string mbti;
    cin >> mbti;

    int n, cnt = 0;
    cin >> n;
    string temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(temp == mbti) cnt++;
    }
    cout << cnt;
}