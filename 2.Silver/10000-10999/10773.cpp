// 제로 - BOJ #10773

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k;
    cin >> k;

    int temp;
    stack<int> stk;
    for(int i = 0; i < k; i++) {
        cin >> temp;
        temp ? stk.push(temp) : stk.pop();
    }

    int sum = 0;
    while(stk.size()) {
        sum += stk.top();
        stk.pop();
    }

    cout << sum;
}