#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string date;
string day;
string weather;

struct info {
    string date;
    string day;
    string weather;
};

int main() {
    cin >> n;
    vector<info> arr;

    for (int i = 0; i < n; i++) {
        cin >> date >> day >> weather;

        if(weather == "Rain")
            arr.push_back({date, day, weather});
    }

    sort(arr.begin(), arr.end(), [](const info a, const info b) {
        return a.date < b.date;
    });

    cout << arr[0].date << " " << arr[0].day << " " << arr[0].weather << endl;

    return 0;
}