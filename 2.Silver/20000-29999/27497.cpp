// ¾ËÆÄºª ºí·Ï - BOJ #27497

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
    
    deque<char> dq;
    stack<bool> track;

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        char input;
        cin >> temp;
        if(temp == 1) {
            track.push(0);
            cin >> input;
            dq.push_back(input);
            continue;
        }

        if(temp == 2) {
            track.push(1);
            cin >> input;
            dq.push_front(input);
            continue;
        }

        if(temp == 3) {
            if(!sz(dq)) continue;
            track.top() ? dq.pop_front() : dq.pop_back();
            track.pop();
        }
    }

    for(auto &i : dq) cout << i;
    if(!sz(dq)) cout << 0;
}