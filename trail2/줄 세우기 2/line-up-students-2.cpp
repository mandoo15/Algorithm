#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int h;
int w;

struct info {
    int h;
    int w;
    int num;
};

int main() {
    cin >> N;

    vector<info> arr;

    for (int i = 0; i < N; i++) {
        cin >> h >> w;

        arr.push_back({h, w, i+1});
    }

    sort(arr.begin(), arr.end(), [](const info a, const info b) {
        if(a.h == b.h) {
            return a.w > b.w;
        }

        return a.h < b.h;
    });

    for(int i=0; i<N; i++) {
        cout << arr[i].h << " " << arr[i].w << " " << arr[i].num << endl;
    }

    return 0;
}