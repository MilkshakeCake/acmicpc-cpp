// 수 찾기 - Baekjoon Online Judge no.1920

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
    vector<int> vec;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());       //sort 안하면 binary_search가 제대로 작동 안함
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> temp;
        cout << binary_search(vec.begin(), vec.end(), temp) << '\n';
    }
}