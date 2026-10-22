/*
사분면은 한 평면을 x, y축을 기준으로 나눈 4분면.
정수배열 dot - x, y를 차례로 담음.
dot이 어디 사분면에 속하는지 1, 2, 3, 4로 return.
*/
class Solution {
    public int solution(int[] dot) {
        int answer = 0;
        if(dot[0] > 0 && dot[1] > 0) answer = 1;
        if(dot[0] < 0 && dot[1] > 0) answer = 2;
        if(dot[0] < 0 && dot[1] < 0) answer = 3;
        if(dot[0] > 0 && dot[1] < 0) answer = 4;
        return answer;
    }
}