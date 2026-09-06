#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string name;
int height;
int weight;

struct info {
    string name;
    int height;
    int weight;
};

int main() {
    cin >> n;

    vector<info> arr;

    for (int i = 0; i < n; i++) {
        cin >> name >> height >> weight;
        arr.push_back({name, height, weight});
    }

    sort(arr.begin(), arr.end(), [](const info a, const info b) {
        return a.height < b.height;
    });

    for(int i=0; i<n; i++) {
        cout << arr[i].name << " " << arr[i].height << " " << arr[i].weight << endl;
    }

    return 0;
}