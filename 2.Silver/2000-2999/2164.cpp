// 카드2 - BOJ #2164

#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    
    while(q.size() > 1) {
    q.pop();
    q.push(q.front());
    q.pop();
    }

    cout << q.front();
}