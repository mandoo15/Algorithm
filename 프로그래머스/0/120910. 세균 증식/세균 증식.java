/*
어떤 세균 : 1시간에 2배씩 증식.
처음 세균 마리 수 n 경과한 시간 t
t시간 후 세균의 수 -> return

*/
class Solution {
    public int solution(int n, int t) {
        int answer = n;
        for(int i=1; i<t+1; i++) {
            answer *= 2;
        }
        return answer;
    }
}