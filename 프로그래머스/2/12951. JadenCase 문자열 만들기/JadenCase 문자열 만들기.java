class Solution {
    public String solution(String s) {
        String[] str = s.split(" ", -1); 
        StringBuilder answer = new StringBuilder();
        
        for (int i = 0; i < str.length; i++) {
            String x = str[i];
            if (x.length() > 0) {
                char c = x.charAt(0);
                if (Character.isLetter(c)) {
                    answer.append(Character.toUpperCase(c));
                    x = x.toLowerCase();
                    answer.append(x.substring(1));
                } else {
                    answer.append(x.toLowerCase());
                }
            }
            if (i != str.length - 1) {
                answer.append(" ");
            }
        }
        
        return answer.toString();
    }
}

