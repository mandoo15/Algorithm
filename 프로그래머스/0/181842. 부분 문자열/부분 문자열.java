/*
어떤 문자열 A가 다른 문자열 B안에 속하면 부분 문자열
str1, str2 str1이 str2의 부분 문자열이면 1 아니면 0 return
*/
class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        if(str2.contains(str1)) answer = 1;
        return answer;
    }
}