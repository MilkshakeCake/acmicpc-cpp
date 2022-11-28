// 리모컨 - BOJ #1107

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> arr(10, true);

int getSize(int n) {
    int size = 1;
    while(n / 10 > 0) {
        n /= 10;
        size++;
    }
    return size;
}

bool check(int num) {
    if(!num && !arr[num]) {
        return false;
    }
    while(num > 0) {
        if(!arr[num % 10]) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int m;
    
    cin >> n >> m;
    while(m--) {
        int temp;
        cin >> temp;
        arr[temp] = false;
    }

    int start = 0;
    if(getSize(n) > 2) start = pow(10, getSize(n) - 2);
    int end = min((int)pow(10, getSize(n) + 1), 1000001);

    int cnt = abs(n - 100);

    for(int i = start; i < end; i++) {
        if(abs(n - i) + getSize(i) < cnt && check(i)) {
            cnt = abs(n - i) + getSize(i);
        }
    }
    cout << cnt;
}