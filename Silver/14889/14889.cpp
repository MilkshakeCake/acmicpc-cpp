#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int N;
int sum = 0;

int main() {
    cin >> N;
    int s[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> s[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            s[i][j] += s[j][i];
            sum += s[i][j];
            s[j][i] = 0;
        }
    }

    vector<int> v;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(s[i][j]) {
                v.push_back(s[i][j]);
            }
        }
    }
    sort(v.begin(), v.end());

    
}