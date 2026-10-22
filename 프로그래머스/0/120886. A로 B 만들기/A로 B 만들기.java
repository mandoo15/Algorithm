import java.util.*;

class Solution {
    public int solution(String before, String after) {
        for(int i=0; i<before.length(); i++){
            after = after.replaceFirst(Character.toString(before.charAt(i)), "");
        }
        int answer = 0;
        if(after.length() == 0) answer = 1;
        return answer;
    }
}