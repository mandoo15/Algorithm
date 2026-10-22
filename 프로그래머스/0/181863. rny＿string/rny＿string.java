/*
m과 rn이 모양이 비슷하게 생긴 점을 활용해 문자열에 장난.
문자열 rny_string
이 문자열의 모든 m을 rn으로 바꾼 문자열을 return
-> replace 함수 사용
* replace 특정 부분만 바꿈 / replaceAll 문자열 길이 전체 변경 / replaceFirst 문자열에서 조건 맞는 처음 것만 바꿈
*/
class Solution {
    public String solution(String rny_string) {
        String answer = rny_string.replace("m", "rn");
        return answer;
    }
}