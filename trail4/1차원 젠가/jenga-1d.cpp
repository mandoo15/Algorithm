#include <iostream>
#include <vector>
using namespace std;

int n;
int blocks[100];
int s1, e1;
int s2, e2;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    vector<int> ans;

    for(int i=0; i<s1-1; i++) {
        ans.push_back(blocks[i]);
    }
    for(int i=e1; i<n; i++) {
        ans.push_back(blocks[i]);
    }

    vector<int> answer;

    for(int i=0; i<s2-1; i++) {
        answer.push_back(ans[i]);
    }
    for(int i=e2; i<ans.size(); i++) {
        answer.push_back(ans[i]);
    }

    cout << answer.size() << endl;
    for(int i=0; i<answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}
