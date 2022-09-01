#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    string str;
    queue<int> que;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(str == "push") {
            cin >> temp;
            que.push(temp);
        }

        else if(str == "pop") {
            if(que.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << que.front() << '\n';
                que.pop();
            }
        }

        else if(str == "size") {
            cout << que.size() << '\n';
        }

        else if(str == "empty") {
            cout << que.empty() << '\n';
        }

        else if(str == "front") {
            if(que.empty()) {
                cout << "-1" << '\n';
            }
            else cout << que.front() << '\n';
        }

        else if(str == "back") {
            if(que.empty()) {
                cout << "-1" << '\n';
            }
            else cout << que.back() << '\n';
        }
    }
    return 0;
}