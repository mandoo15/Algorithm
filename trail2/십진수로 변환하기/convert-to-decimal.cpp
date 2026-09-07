#include <iostream>
#include <vector>
using namespace std;

char binary[9];

int main() {
    cin >> binary;

    vector<int> arr;
    vector<int> brr;

    int sum = 0;

    for(int i=0; i<9; i++) {
        if(binary[i] == '\0') break;

        int n = binary[i] - '0';
        arr.push_back(n);
    }
    
    for(int i=0; i<arr.size(); i++) {
        int two = 1;

        for(int j=0; j<i; j++) {
            two *= 2;
        }
        brr.push_back(two);
    }

    for(int i=0; i<arr.size(); i++) {
        sum += arr[i] * brr[brr.size()-1-i];
    }

    cout << sum;

    return 0;
}