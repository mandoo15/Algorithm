/*
숫자와 z가 공백으로 구분된 문자열 // 숫자, 공백, z
문자열 숫자를 차레대로 더하려고 한다.
만약 z가 나오면 바로 전에 더했던 숫자를 뺀다는 뜻.
 문자열 s가 주어질 때 구한 값  return
*/
class Solution {
    public int solution(String s) {
        String[] str = s.split(" ");
        int answer = 0;
        for(int i=0; i<str.length; i++) {
            if(str[i].equals("Z")){
                answer -= Integer.parseInt(str[i-1]);
            } else {
                answer += Integer.parseInt(str[i]);
            }
        }
        return answer;
    }
}