#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string N;
int sum = 0;

int main() {
    cin >> N;

    vector<int> arr;
    vector<int> brr;

    for(int i=0; i<N.length(); i++) {
        int a = (int)(N[i] - '0'); 
        arr.push_back(a);
    }

    for(int i=N.length()-1; i>=0; i--) {
        int two = 1;

        for(int j=0; j<i; j++) {
            two *= 2;
        }

        brr.push_back(two);
    }

    int sum = 0;

    for(int i=0; i<arr.size(); i++) {
        sum += arr[i] * brr[i];
    }

    sum *= 17;
    string ans;
    while(sum >= 2) {
        int mok = sum / 2;
        int nam = sum % 2;

        ans += (nam + '0');

        sum = mok;
    }
    ans += (sum + '0');

    for(int i=ans.length()-1; i>=0; i--) cout << ans[i];

    return 0;
}