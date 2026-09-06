#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string name;
int korean;
int english;
int math;

struct score {
    string name;
    int kor;
    int eng;
    int mat;
};

int main() {
    cin >> n;

    vector<score> arr;

    for (int i = 0; i < n; i++) {
        cin >> name >> korean >> english >> math;

        arr.push_back({name, korean, english, math});
    }

    sort(arr.begin(), arr.end(), [](const score a, const score b) {
        if(a.kor == b.kor) {
            if(a.eng == b.eng) {
                return a.mat > b.mat;
            }
            
            return a.eng > b.eng;
        }

        return a.kor > b.kor;
    });

    for(int i=0; i<n; i++) {
        cout << arr[i].name << " " << arr[i].kor << " " << arr[i].eng << " " << arr[i].mat << endl;
    }
    return 0;
}