#include <string>
#include <vector>

using namespace std;
vector<int> arr;
int cnt = 0;

void check(int target, int sum, int level) {
    
    if(level == arr.size()) {
        if(sum == target) {
        cnt++;
        }
        return;
    }
    
    //if(sum > target) return;
    check(target, sum + arr[level], level + 1);
    check(target, sum - arr[level], level + 1);
}

int solution(vector<int> numbers, int target) {
    arr = numbers;
    
    check(target, 0, 0);
    
    return cnt;
}