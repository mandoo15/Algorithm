#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

string name;
int height;
double weight;

struct info {
    string n;
    int h;
    double w;
};

int main() {

    vector<info> arr;

    for (int i = 0; i < 5; i++) {
        cin >> name >> height >> weight;

        arr.push_back({name, height, weight});
    }

    sort(arr.begin(), arr.end(), [](const info a, const info b) {
        return a.n < b.n;
    });

    cout << "name" << endl;
    for(int i=0; i<5; i++) {
        cout << arr[i].n << " " << arr[i].h << " " << fixed << setprecision(1) << arr[i].w << endl;
    }

    sort(arr.begin(), arr.end(), [](const info a, const info b) {
        return a.h > b.h;
    });

    cout << endl << "height" << endl;
    for(int i=0; i<5; i++) {
        cout << arr[i].n << " " << arr[i].h << " " << fixed << setprecision(1) << arr[i].w << endl;
    }

    return 0;
}