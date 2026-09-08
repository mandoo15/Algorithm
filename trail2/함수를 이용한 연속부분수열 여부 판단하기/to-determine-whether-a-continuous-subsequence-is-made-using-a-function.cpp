#include <iostream>

using namespace std;

int n1, n2;
int a[100], b[100];

int main() {
    cin >> n1 >> n2;

    for (int i = 0; i < n1; i++) cin >> a[i];

    for (int i = 0; i < n2; i++) cin >> b[i];

    if(n1 < n2) {
        cout << "No";
        return 0;
    }

    int cnt = 0, ind = 0;
    for(int i=0; i<n1; i++) {
        cnt = 0;
        ind = 0;
        for(int j=i; j<i+n2; j++) {
            if(a[j] == b[ind]) {
                cnt++;
            }
            ind++;
        }
        if(cnt == n2) {
        cout << "Yes";
        return 0;
        }
    }

    cout << "No";
    return 0;
}