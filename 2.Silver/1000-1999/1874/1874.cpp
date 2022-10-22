// 스택 수열 - Baekjoon Online Judge no.1874

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack<int> stk;

    int n;
    cin >> n;

    vector<int> arr;
    int temp;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    vector<char> ch;
    int next = 0;
    
    for(int i = 1; i <= n; i++) {
        stk.push(i);
        ch.push_back('+');

        while(!stk.empty() && stk.top() == arr[next]) {
            stk.pop();
            ch.push_back('-');
            next++;
        }
    }

    if(!stk.empty()) {
        cout << "NO";
        return 0;
    }

    for(unsigned int i = 0; i < ch.size(); i++) {
        cout << ch[i] << '\n';
    }
}