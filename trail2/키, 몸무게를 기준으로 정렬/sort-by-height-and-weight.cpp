#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;
string n;
int h;
int w;

struct info {
    string n;
    int h;
    int w;
};

int main() {
    cin >> num;

    vector<info> arr;

    for (int i = 0; i < num; i++) {
        cin >> n >> h >> w;

        arr.push_back({n, h, w});
    }

    sort(arr.begin(), arr.end(), [](const info a, const info b) {
        if(a.h == b.h) {
            return a.w > b.w;
        }
        return a.h < b.h;
    });

    for(int i=0; i<num; i++) {
        cout << arr[i].n << " " << arr[i].h << " " << arr[i].w << endl;
    }

    

    return 0;
}