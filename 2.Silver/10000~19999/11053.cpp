// 가장 긴 증가하는 부분 수열 - Baekjoon Online Judge no.11053

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> arr;
    vector<int> dp(1001, 1);

    int temp;
    F_OR1(n) {
        cin >> temp;
        arr.push_back(temp);
    }

    F_OR3(i, 1, n) {
        F_OR3(j, 0, i) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[max_element(all(dp)) - dp.begin()];
}