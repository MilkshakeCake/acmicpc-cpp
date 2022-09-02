#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k, n;
    cin >> k >> n;
    
    vector<int> v;
    int temp;
    for(int i = 0; i < k; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    long long snum = 1;
    long long lnum = v[v.size()-1];

    while(snum <= lnum) {
        long long iter = (snum + lnum) / 2;
        long long cnt = 0;
        for(int i = 0; i < k; i++) {
            cnt += v[i] / iter;
        }
        if(cnt < n) {
            lnum = iter - 1;
        }
        else {
            snum = iter + 1;
        }
    }

    cout << lnum;
}