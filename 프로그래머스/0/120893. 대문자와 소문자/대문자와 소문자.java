/*
문자열 my_string 매개변수
대문자는 소문자로 소문자는 대문자로 변환.
--HOW?
for문 이용 -> 새로운 문자열에 변환한 글자 넣기
ASCII 코드 이용 - if문으로 조건 달아서.
대문자 : 65-90
소문자 : 97-122
대문자로 바꿀 때 : 소문자의 ASCII코드 - 32
소문자로 바꿀 때 : 대문자의 ASCII코드 + 32

*/
class Solution {
    public String solution(String my_string) {
        String answer = "";
        for(int i=0; i<my_string.length(); i++){
            if( 65 <= (int)(my_string.charAt(i)) && (int)(my_string.charAt(i)) <= 90){
                answer += Character.toString(my_string.charAt(i) + (char)(32));
            }
            else {
                answer += Character.toString(my_string.charAt(i) - (char)(32));
            }
        }
        return answer;
    }
}