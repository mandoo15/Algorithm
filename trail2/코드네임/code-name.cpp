#include <iostream>
#include <algorithm>
#define MAX_N 5

using namespace std;

class User {
public:
    char code_name;
    int score;
};

User users[MAX_N];

int main() {
    for (int i = 0; i < MAX_N; i++) {
        cin >> users[i].code_name >> users[i].score;
    }

    sort(users, users + MAX_N, [](const User a, const User b) {
        return a.score < b.score;
    });

    cout << users[0].code_name << " " << users[0].score;

    return 0;
}
