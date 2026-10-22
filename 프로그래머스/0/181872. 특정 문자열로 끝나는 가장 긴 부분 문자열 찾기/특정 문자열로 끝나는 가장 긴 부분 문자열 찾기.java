class Solution {
    public String solution(String myString, String pat) {
        int laind = myString.lastIndexOf(pat);
        if (laind == -1) return "";
        return myString.substring(0, laind + pat.length());
    }
}
