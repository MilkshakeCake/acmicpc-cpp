#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int MONEY, K;
    cin >> MONEY >> K;
    vector<int> skill[5];
    for(int i = 0; i < 5; i++) {
        int maxlvl;
        cin >> maxlvl;
        int temp;
        for(int j = 0; j < maxlvl; j++) {
            cin >> temp;
            skill[i].push_back(temp + skill[i].back());
        }
    }

    vector<vector<int>> armor[3];

    for(int i = 0; i < 3; i++) {
        int M;
        cin >> M;
        vector<int> part;
        int temp;
        for(int j = 0; j < M; j++) {
            cin >> temp;
            part.push_back(temp);
        }
        armor[i].push_back(part);

        for(int j = 0; j < M; j++) {
            for(int k = 0; k < 5; k++) {
                cin >> temp;
                armor[i][j].push_back(temp);
            }
        }
    }
    // input finish

    int dps[3];

    for(int i = 0; i < armor[0].size(); i++) {
        int sum = 0;
        for(int j = 0; j < 5; j++) {
            sum += skill[j][armor[0][i][j]];
        }
    }
}