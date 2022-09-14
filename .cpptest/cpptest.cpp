// Practice techniques of C++

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <map>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main() {
    int n, temp;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    vector<pair<int, int> > pr;
    for(int i = 0; i < n; i++) {
        pr.push_back(make_pair(v[i], i));
    }
    sort(all(pr));

    cout << pr[0].second;
}