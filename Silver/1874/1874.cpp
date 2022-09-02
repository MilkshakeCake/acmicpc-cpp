#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack<int> stk;
    stk.push(0);
    int n;
    cin >> n;
    int temp;
    vector<char> ch;
    int next = 1;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(stk.top() > temp) {
            cout << "NO";
            return 0;
        }
        while(temp > stk.top()) {
            stk.push(next++);
            ch.push_back('+');
        }
        if(stk.empty()) continue;
        stk.pop();
        ch.push_back('-');
    }
    for(unsigned int i = 0; i < ch.size() - 1; i++) {
        cout << ch[i] << '\n';
    }
}