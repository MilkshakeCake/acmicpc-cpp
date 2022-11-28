// 프린터 큐 - BOJ #1966

#include <bits/stdc++.h>

using namespace std;

// bool operator< () {
//         if(str1.index == str2.index) {
//             return str1.key > str2.key;
//         }
//         return str1.index < str2.index;
//     }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        priority_queue<int> pq;
        queue<pair<int, int> > que;
        int temp;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            pq.push(temp);
            que.push(make_pair(i, temp));
        }

        int cnt = 0;
        while(true) {
            int idx = que.front().first;

            if(pq.top() > que.front().second) {
                que.push(que.front());
                que.pop();
            }

            else {
                que.pop();
                pq.pop();
                cnt++;
                if(idx == m) {
                    cout << cnt << '\n';
                    break;
                }
            }
        }
    }
}