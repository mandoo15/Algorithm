class Solution {
    public String solution(String n_str) {
        String answer = "";
        int x = 0;
        for(int i=0; i<n_str.length(); i++){
            if(n_str.charAt(i) != '0'){
                x = i;
                break;
            }
        }
        for(int i=x; i<n_str.length(); i++){
            answer += n_str.charAt(i);
        }
        return answer;
    }
}