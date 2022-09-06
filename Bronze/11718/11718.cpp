// 그대로 출력하기 - Baekjoon Online Judge no.11718

#include <string>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    while(true) {
        getline(cin, str);
        if(!str.size()) {
            break;
        }
        cout << str << '\n';
    }
}