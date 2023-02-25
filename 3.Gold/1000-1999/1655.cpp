// 가운데를 말해요 - BOJ #1655

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

    priority_queue<int, vt<int>, less<int>> maximal;
    priority_queue<int, vt<int>, greater<int>> minimal;

    int n;
    cin >> n;

    int temp;
    cin >> temp;
    maximal.push(temp);
    n--;

    cout << temp << '\n';

    while(n--) {
        cin >> temp;
        if(maximal.size() == minimal.size()) {
            maximal.push(temp);
        }

        else {
            minimal.push(temp);
        }
        
        if(maximal.top() > minimal.top()) {
            temp = maximal.top();
            maximal.pop();
            maximal.push(minimal.top());
            minimal.pop();
            minimal.push(temp);
        }

        cout << maximal.top() << '\n';
    }
}