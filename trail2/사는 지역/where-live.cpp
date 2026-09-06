#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int n;
string name, address, region;

struct info {
    string name;
    string address;
    string city;
};

int main() {
    cin >> n;

    vector<info> arr;

    for (int i = 0; i < n; i++) {
        cin >> name >> address >> region;

        arr.push_back({name, address, region});
    }

    sort(arr.begin(), arr.end(), [](const info a, const info b) {
        return a.name > b.name;
    });

    cout << "name " << arr[0].name << endl;
    cout << "addr " << arr[0].address << endl;
    cout << "city " << arr[0].city << endl;

    return 0;
}
