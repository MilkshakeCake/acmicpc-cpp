// 잃어버린 괄호 - BOJ #1541
// longest subtraction interval

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

int sum = 0;

int main() {
    string input;
    cin >> input;
 
    int result = 0;
    string num;
    bool isMinus = false;
 
    for (int i = 0; i <= input.size(); i++) {
        
        if (input[i] == '-' || input[i] == '+' || i==input.size()) {
            if (isMinus) {
                result -= stoi(num);
                num = "";
            }
            else {
                result += stoi(num);
                num = "";
            }
        }
        else {
            num += input[i];
        }
 
        if (input[i] == '-') {
            isMinus = true;
        }    
    }
    
    cout << result;
}
