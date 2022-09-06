// 마인크래프트 - Baekjoon Online Judge no.18111

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

const int INF = 1e9 + 7;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n, m, j;
    cin >> n >> m >> j;
    int floor, ceil, temp;
    floor = 257;
    ceil = 0;
    map<int, int> myMap; // key : given height (ex : 63, 64) val : count of heights that are shown
    for(int i = 0; i < (n * m); i++) {
        std::cin >> temp;
        myMap[temp]++;

        if(temp > ceil) {
            ceil = temp;
        }
        else if(temp < floor) {
            floor = temp;
        }
    }

    int mintm = INF;
    int maxH = 0;
    int jpres = j;

    for(int height = floor; height <= ceil; height++) { // each case of possible heights
        int time = 0;
        int jpr = 0;
        j = jpres;

        // sum worktime thru loop
        for(auto& i : myMap) {
            if(i.first > height){
                time += 2 * i.second * (i.first - height);
                j += i.second * (i.first - height);
            }

            else {
                time += i.second * (height - i.first);
                jpr += i.second * (height - i.first);
            }
        }

        if(j >= jpr) {
            if (time < mintm) {
                mintm = time;
                maxH = height;
            }
            else if(time == mintm && height > maxH) {
                maxH = height;
            }
        }
    }
    std::cout << mintm << ' ' << maxH;
}