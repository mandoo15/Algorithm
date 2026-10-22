/*
문자 A와 B로 이루어진 문자열 myString과 pat
myString의 A를 B로 바꾼 문자열의 연속하는 부분 문자열 중 pat이 있으면 1 아니면 0
-> replace 함수와 contains함수 사용
*/
class Solution {
    public int solution(String myString, String pat) {
        int answer = 0;
        myString = myString.replace("A", "C");
        myString = myString.replace("B", "A");
        myString = myString.replace("C", "B");
        if(myString.contains(pat)) answer = 1;
        return answer;
    }
}