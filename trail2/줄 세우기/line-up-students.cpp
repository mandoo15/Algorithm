#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int h;
int w;

struct info {
    int height;
    int weight;
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
        if(a.height == b.height) {
            if(a.weight == b.weight) {
                return a.num < b.num;
            }

            return a.weight > b.weight;
        }

        return a.height > b.height;

    });

    for(int i=0; i<N; i++) {
        cout << arr[i].height << " " << arr[i].weight << " " << arr[i].num << endl;
    }


    return 0;
}
