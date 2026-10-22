/*
대문자와 소문자가 섞여 있는 문자열 s
s에 'p'의 개수와 'y'의 개수를 배교해 같으면 true, 다르면 false return
-> 아무도 없으면 true
*/
class Solution {
    boolean solution(String s) {
        boolean answer = true;
        s = s.toLowerCase();
        
        int cntp = 0, cnty = 0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == 'p') cntp++;
            if(s.charAt(i) == 'y') cnty++;
        }
        
        if(cntp != cnty) answer = false;  

        return answer;
    }
}