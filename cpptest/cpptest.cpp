#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int sum = 0;
    int arr[5];
    int arr2[5];
    for(int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10;
        arr2[i] = arr[i] % 7;
        sum += arr2[i];
    }
    sum %= 7;
    if(sum == 3) cout << 'y';
}