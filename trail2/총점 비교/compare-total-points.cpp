#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string name;
int score1;
int score2;
int score3;

struct info {
    string name;
    int sc1;
    int sc2;
    int sc3;
};

int main() {
    cin >> n;

    vector<info> arr;

    for (int i = 0; i < n; i++) {
        cin >> name >> score1 >> score2 >> score3;

        arr.push_back({name, score1, score2, score3});
    }

    sort(arr.begin(), arr.end(), [](const info a, const info b) {
        return a.sc1 + a.sc2 + a.sc3 < b.sc1 + b.sc2 + b.sc3;
    });

    for(int i=0; i<n; i++) {
        cout << arr[i].name << " " << arr[i].sc1 << " " << arr[i].sc2 << " " << arr[i].sc3 << endl;
    }
    

    return 0;
}