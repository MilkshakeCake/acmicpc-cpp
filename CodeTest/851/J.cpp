// 최대 상승 - 충남대학교 SW_IT Contest J
// BOJ #25644

#include <bits/stdc++.h>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int arr[200000];
    vector<int> profit(200000, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++) {
        profit[i] = max(profit[i -1] + arr[i] - arr[i -1], 0);
    }
    cout << profit[max_element(profit.begin(), profit.end()) - profit.begin()];
}