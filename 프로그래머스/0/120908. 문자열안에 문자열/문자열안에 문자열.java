/*
문자열 str1, str2 매개변수
str1 안에 str2가 있으면 1 아니면 2 return 
*/
// contains() 함수 : String에서 제공하는 contains() 메서드를 사용하여 특정 문자열이 존재하는지 확인할 수 있습니다. 특정 문자열을 인수로 전달하여 존재하면 true, 그렇지 않으면 false가 반환됩니다.
// 사용범 ex ) str.contains("안녕");
class Solution {
    public int solution(String str1, String str2) {
        int answer = 2;
        if(str1.contains(str2)) answer = 1;
        return answer;
    }
}