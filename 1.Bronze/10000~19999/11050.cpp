// 이항 계수 1 - Baekjoon Online Judge no. 11050

#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
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
        arr[n][k] = binomial(n-1, k-1) + binomial(n-1, k);
        return arr[n][k];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    cout << binomial(n, k);
}