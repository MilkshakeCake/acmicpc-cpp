#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    string str;
    stack<int> stak;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(str == "push") {
            cin >> temp;
            stak.push(temp);
        }

        else if(str == "pop") {
            if(stak.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << stak.top() << '\n';
                stak.pop();
            }
        }

        else if(str == "size") {
            cout << stak.size() << '\n';
        }

        else if(str == "empty") {
            cout << stak.empty() << '\n';
        }

        else if(str == "top") {
            if(stak.empty()) {
                cout << "-1" << '\n';
            }
            else cout << stak.top() << '\n';
        }
    }
    return 0;
}