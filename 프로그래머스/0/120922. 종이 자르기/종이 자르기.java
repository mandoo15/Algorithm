/*
MXN 크기의 종이를 최소로 가위질 해야 하는 횟수? ( to 1X1 )

*/
class Solution {
    public int solution(int M, int N) {
        int answer = 0;
        answer += (M-1);
        answer += M*(N-1);
        return answer;
    }
}