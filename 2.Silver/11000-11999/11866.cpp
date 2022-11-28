//요세푸스 문제 0 - BOJ #11866

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    queue<int> ueue;
    for(int i = 1; i <= n; i++) {
        ueue.push(i);
    }

    cout << '<';
    
    while(--n) {
        for(int i = 0; i < k - 1; i++) {
            ueue.push(ueue.front());
            ueue.pop();
        }
        cout << ueue.front() << ", ";
        ueue.pop();
    }
    cout << ueue.front() << '>';
}