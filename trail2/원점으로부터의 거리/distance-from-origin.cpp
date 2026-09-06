#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int x;
int y;

struct info {
    int x;
    int y;
    int num;
};

int main() {
    cin >> N;

    vector<info> arr;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;

        arr.push_back({x, y, i+1});
    }


    sort(arr.begin(), arr.end(), [](const info a, const info b) {
        if(abs(a.x) + abs(a.y) == abs(b.x) + abs(b.y)) {
            return a.num < b.num;
        }

        return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
    });

    for(int i=0; i<N; i++) {
        cout << arr[i].num << endl;
    }

    return 0;
}
