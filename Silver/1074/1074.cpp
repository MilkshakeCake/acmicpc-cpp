// Z - Baekjoon Online Judge no.1074

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int big = 0;
int small = 0;
int bigger(int a, int b) {
    big = a >= b ? a : b;
    return big;
}
int smaller(int a, int b) {
    small = a <= b ? a : b;
    return small;
}

vector<vector<int> > v;

int recursive(int r, int c, vector<vector<int> > v) {
    int** pt;
    if(r < 2 && c < 2) {
        v[r][c] = 2 * r + c;
        return v[r][c];
    }

    int i1 = 1;
    while(r != r % i1) i1 *= 2;
    int i2 = 1;
    while(c != c % i2) i2 *= 2;

    int b = bigger(i1, i2);
    int s = smaller(i1, i2);
    
    if(s == b) {

    }
    else if(s <= b / 2) {
        if(i1 == s){
            v[r][c] = recursive(r, c-b/2, v) + b * b / 4;
        }
        else if(i2 == s){
            v[r][c] = recursive(r-b/2, c, v) + b * b / 2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, r, c;
    cin >> n >> r >> c;
    int i1 = 1;
    int i2 = 1;
    while(r != r % i1) {
        i1 *= 2;
    }
    while(c != c % i2) {
        i2 *= 2;
    }

    int* arr[bigger(i1, i2)];
    for(int i = 0; i < big; i++) {
        arr[i] = new int[big];
    }


}