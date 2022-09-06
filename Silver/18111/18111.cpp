// "Project_Name" - Baekjoon Online Judge no."Project_Num"

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

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
    vector<int> idxVec; // array of given heights of each cell
    for(int i = 0; i < (n * m); i++) {
        std::cin >> temp;
        myMap[temp]++;
        sort(idxVec.begin(), idxVec.end());
        if(!binary_search(idxVec.begin(), idxVec.end(), temp)) {
            idxVec.push_back(temp);
        }

        if(temp > ceil) {
            ceil = temp;
        }
        else if(temp < floor) {
            floor = temp;
        }
    }

    int mintm = 257;
    int maxH = 0;

    sort(idxVec.begin(), idxVec.end());

    for(int height = floor; height <= ceil; height++) { // each case of possible heights
        int time = 0;
        int jpr = 0;

        // sum worktime thru loop
        for(unsigned int i = 0; i < idxVec.size(); i++) {
            if(idxVec[i] > height){
                time += 2 * myMap[idxVec[i]] * (idxVec[i] - height);
                j += myMap[idxVec[i]] * (idxVec[i] - height);
            }

            else {
                time += myMap[idxVec[i]] * (height - idxVec[i]);
                jpr += myMap[idxVec[i]] * (height - idxVec[i]);
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