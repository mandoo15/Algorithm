/*
array 정수 배열 매개변수,
7이 총 몇 개인지?
*/
class Solution {
    public int solution(int[] array) {
        int answer = 0;
        for(int i=0; i<array.length; i++){
            String s = Integer.toString(array[i]);
            int oglen = s.length();
            s = s.replace("7", "");
            int newlen = s.length();
            answer += oglen - newlen;
        }
        return answer;
    }
}