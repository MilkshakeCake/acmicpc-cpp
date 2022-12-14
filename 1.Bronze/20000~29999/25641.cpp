// 균형 잡힌 소떡소떡 - BOJ #25641

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
    int n;
    cin >> n;
    int s = 0;
    int t = 0;
    queue<bool> stst;
    char temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(temp == 's') {
            stst.push(true);
            s++;
        }

        else {
            stst.push(false);
            t++;
        }
    }

    while(s != t) {
        stst.front() ? s-- : t--;
        stst.pop();
    }

    int size = (int)stst.size();

    for(int i = 0; i < size; i++) {
        if(stst.front()) cout << 's';
        else cout << 't';
        stst.pop();
    }
}