/*
어떤 정수의 절댓값을 차례대로 담은 정수 배열 absolutes
정수들의 부호를 차례대로 담은 불리언 배열 signs
실제 정수들의 합을 구하여 return

--> signs가 만약 true이면 + false 이면 -
signs에서 signs[i]가 false -> absolutes[i] *= -1;
하고 answer += absoulutes[i];
*/
class Solution {
    public int solution(int[] absolutes, boolean[] signs) {
        int answer = 0;
        for(int i=0; i<signs.length; i++){
            if(!signs[i]) absolutes[i] *= -1;
            answer += absolutes[i];
        }
        return answer;
    }
}