#include <iostream>

using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int dp[1001][1001] = {};
    for(int row = 1; row <= N; row++){
        for (int col = 0; col <= N; col++) {
            if (row == col || col == 0) {
                dp[row][col] = 1; continue;
            }
            dp[row][col] = (dp[row - 1][col] + dp[row - 1][col - 1]) % 10007;
        }
    }
    printf("%d", dp[N][K]);
    return 0;
}
