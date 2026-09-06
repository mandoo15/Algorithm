#include <iostream>
#include <string>

using namespace std;

string product_name;
int product_code;

struct info {
    string name;
    int code;
};

int main() {
    cin >> product_name >> product_code;

    info x;
    x.name = "codetree";
    x.code = 50;
    cout << "product " << x.code << " is " << x.name << endl;

    x.name = product_name;
    x.code = product_code;
    cout << "product " << x.code << " is " << x.name << endl;

    return 0;
}