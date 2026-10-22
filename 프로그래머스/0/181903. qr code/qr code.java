// code의 인덱스를 q로 나눴을 때 나머지 r인 위치의 문자를 순서대로 이어붙인 문자열 return
class Solution {
    public String solution(int q, int r, String code) {
        String answer = "";
        for(int i=0; i<code.length(); i++){
            if(i%q==r) answer += code.charAt(i);
        }
        return answer;
    }
}