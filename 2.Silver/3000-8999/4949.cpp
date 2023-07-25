// 균형잡힌 세상 - BOJ #4949

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        string temp;
        getline(cin, temp);

        if(temp == ".") {
            break;
        }

        stack<char> stk;
        bool result = false;
        for(unsigned int i = 0; i < temp.length(); i++) {
            char ch = temp[i];

            if(ch == '(' || ch == '[') {
                stk.push(ch);
            }

            else if(ch == ')') {
                if(!stk.empty() && stk.top() == '(') {
                    stk.pop();
                }
                else {
                    result = true;
                    break;
                }
            }
            else if(ch == ']') {
                if(!stk.empty() && stk.top() == '[') {
                    stk.pop();
                }
                
                else {
                    result = true;
                    break;
                }
            }
        }
        
        if(!result && stk.empty()) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
}