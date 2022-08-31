#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int cnt1 = 0;
int cnt2 = 0;

int fib1(int n) {
    if(n == 1 || n == 2) {
        cnt1++;
        return 1;
    }
    else {
        return (fib1(n - 1) + fib1(n - 2));
    }
}

int f[40];
int fib2(int n) {
    if(n <= 1) {
        return 1;
    }
    for(int i = 3; i <= n; i++) {
        cnt2++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];

}

int main() {
    int n;
    cin >> n;
    fib1(n);
    fib2(n);
    cout << cnt1 << ' ' << cnt2;
}