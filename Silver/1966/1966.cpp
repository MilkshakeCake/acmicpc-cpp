#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

struct myStruct {
    int key;
    int index;
    myStruct(int k, int idx) : key(k), index(idx) {}
};

struct myCompare {
    inline bool operator() (const myStruct& str1, const myStruct& str2) {
        return (str1.key < str2.key);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<int> v;
        int vtmp;
        for(int i = 0; i < n; i++) {
            cin >> vtmp;
            v.push_back(vtmp);
        }
        sort(v.begin(), v.end(), myCompare());
    }
}