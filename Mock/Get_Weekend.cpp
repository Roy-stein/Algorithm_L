#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

int Month[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int MonthDay[2][13]={{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
string Week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
unordered_map<string , int> mp;

bool isLeap(int year){
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int day, month, year;
string mm;

int main(){
    mp["January"] = 1;
    mp["February"] = 2;
    mp["March"] = 3;
    mp["April"] = 4;
    mp["May"] = 5;
    mp["June"] = 6;
    mp["July"] = 7;
    mp["August"] = 8;
    mp["September"] = 9;
    mp["October"] = 10;
    mp["November"] = 11;
    mp["December"] = 12;
    while(cin >> day >> mm >> year){
        month = mp[mm];
        int days = 0;
        for(int i = 1; i < year; ++i){
            if(isLeap(i)){
                days += 366;
            }
            else
                days += 365;
        }
        int u = isLeap(year);
        for(int i = 1; i < month; ++i){
            days += MonthDay[u][i];
        }
        days += day;
        days -= 1;
        days %= 7;
        cout << Week[days] << endl;
    }
}
