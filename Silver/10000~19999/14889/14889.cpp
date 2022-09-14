// 스타트와 링크 - Baekjoon Online Judge no.14889

#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

bool arr[20];
int N;
int mymin = 50000;
int s[20][20];

void mkteam(int index, int cnt) {
    vector<int> start, link;
    int stscore = 0;
    int lkscore = 0;
    if(cnt == (N / 2)) {
        for(int i = 0; i < N; i++) {
            if(arr[i]) {
                start.push_back(i);
            }
            else {
                link.push_back(i);
            }
        }

        for(int i = 0; i < (N / 2); i++) {
            for(int j = 0; j < (N / 2); j++) {
                stscore += s[start[i]][start[j]];
                lkscore += s[link[i]][link[j]];
            }
        }

        if(abs(stscore - lkscore) < mymin) {
            mymin = abs(stscore - lkscore);
        }
    }

    for(int i = index; i < N; i++) {
        if(arr[i]) {
            continue;
        }
        else {
            arr[i] = true;
            mkteam(index, cnt + 1);
            arr[i] = false;
        }
    }
} 

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> s[i][j];
        }
    }
    mkteam(0, 0);
    cout << mymin;
}

//time out