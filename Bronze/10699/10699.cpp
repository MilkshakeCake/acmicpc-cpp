// 오늘 날짜 - Baekjoon Online Judge no.10699

#include <iostream>
#include <ctime>
#include <string>

using namespace std;



int main() {
    struct tm *t;
    time_t timer;
    timer = time(NULL);
    t = localtime(&timer);
    cout << t->tm_year + 1900 << '-';
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mon + 1 << '-';
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mday;
}