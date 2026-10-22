import java.util.*;

class Solution {
    public String remove(String myString) {
        Set<Character> seen = new LinkedHashSet<>();
        StringBuilder result = new StringBuilder();

        for (char ch : myString.toCharArray()) {
            if (!seen.contains(ch)) {
                seen.add(ch);
                result.append(ch);
            }
        }
        return result.toString();
    }
    
    public String solution(String my_string) {
        Solution sol = new Solution();
        String answer = sol.remove(my_string);
        return answer;
    }
}