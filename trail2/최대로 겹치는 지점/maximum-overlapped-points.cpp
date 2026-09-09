#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x1[100], x2[100];

int line[101] = {0};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];

        for(int j=x1[i]; j<=x2[i]; j++) {
            line[j]++;
        }
    }

    sort(line, line + 101);

    cout << line[100];


    return 0;
}