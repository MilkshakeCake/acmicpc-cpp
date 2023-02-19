// 알파벳 블록 - BOJ #949-4

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
    
    deque<char> dq;
    vt<int> tracker(1000000, 0);
    int n, delcnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        char input;
        cin >> temp;
        if(temp == 1) {
            delcnt = 0;
            tracker[i] = 0;
            cin >> input;
            dq.push_back(input);
            continue;
        }

        if(temp == 2) {
            delcnt = 0;
            tracker[i] = 1;
            cin >> input;
            dq.push_front(input);
            continue;
        }

        if(temp == 3) {
            tracker[i] = -1;
            if(!sz(dq)) continue;
            int mostrecent = 0;
            while(tracker[i - mostrecent] == -1) mostrecent++;
            !tracker[i - mostrecent - delcnt] ? dq.pop_back() : dq.pop_front();
            delcnt++;
        }
    }

    for(auto &i : dq) cout << i;
    if(!sz(dq)) cout << 0;
}