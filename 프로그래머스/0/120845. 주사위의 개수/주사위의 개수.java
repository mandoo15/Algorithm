/*
직육면체 모양의 상자에 정육면체 모양의 주사위를 최대한 많이 채우려면?
상자의 가로, 세로, 높이가 저장되어 있는 배열 box
주사위 모서리의 길이 정수 n
상자에 들어갈 수 있는 주사위의 최대 개수를 return
ex > 
box [1, 1, 1]
n 1
result 1

box [10, 6, 8] 가로 세로 높이
n 3
result 12
// 10으로 봤을 때 3, 6으로 봤을 때 2 = 3*2 8이면 또 2 3*2*2
결국 : 각 가로 세로 높이를 나눈 몫의 곱들이 return값이 된다.
--> HOW?
box의 길이는 3으로 제한되어 있으니, answer = box[0]/n + box[1]/n + box[2]/n;
*/
class Solution {
    public int solution(int[] box, int n) {
        int answer = 1;
        for(int i=0; i<box.length; i++){
            answer *= box[i]/n;
        }
        return answer;
    }
}