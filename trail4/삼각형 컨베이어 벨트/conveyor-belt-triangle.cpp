#include <iostream>
#include <vector>

using namespace std;

int n, t;
int l[200];
int r[200];
int d[200];

// 시계방향으로 한 칸씩 회전

int main() {
    cin >> n >> t;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        cin >> l[i];
        arr.push_back(l[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> r[i];
        arr.push_back(r[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> d[i];
        arr.push_back(d[i]);
    }

    for(int i=0; i<t; i++) {

        int temp = arr[3*n-1];

        for(int j=3*n-1; j>=1; j--) {
            arr[j] = arr[j-1];
        }

        arr[0] = temp;
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i=n; i<2*n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i=2*n; i<3*n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
