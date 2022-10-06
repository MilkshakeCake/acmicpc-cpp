// 이항 계수 2 - Baekjoon Online Judge #11051

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int arr[1001][1001] = {};
int binomial(int n, int k) {
    if(n <= 1 || k == 0) {
        if(k > n) {
            arr[n][k] = 0;
            return 0;
        }
        arr[n][k] = 1;
        return 1;
    }
    else {
        if(arr[n][k] != 0) {
            arr[n][k] %= 10007;
            return arr[n][k];
        }
        
        arr[n][k] = binomial(n-1, k-1) + binomial(n-1, k);
        arr[n][n - k] ? arr[n][k] : arr[n][n-k] = arr[n][k];
        arr[n][k] %= 10007;
        return arr[n][k];
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", binomial(n, k));
}