#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    while(v.size() > 1) {
        v.erase(v.begin());

        v.push_back(v[0]);

        v.erase(v.begin());
    }
    cout << v[0];
}