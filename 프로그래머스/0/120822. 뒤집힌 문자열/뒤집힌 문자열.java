class Solution {
    public String solution(String string) {
        String answer = "";
        for(int i=string.length()-1; i>-1; i--){
            char ch = string.charAt(i);
            answer += Character.toString(ch);
        }
           
        return answer;
    }
}