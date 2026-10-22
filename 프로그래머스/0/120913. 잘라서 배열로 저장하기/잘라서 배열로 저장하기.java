/*
my_str 문자열
정수 n 
my_str을 n씩 잘라서 저장한 배열을 return
*/
import java.util.*;
class Solution {
    public String[] solution(String my_str, int n) {
    String[] answer = new String[(int)Math.ceil((double)my_str.length()/n)];
        int i = 0;
        while(my_str.length() > n) {
            answer[i] = my_str.substring(0, n);
            my_str = my_str.substring(n, my_str.length());
            i++;
        }
        answer[i] = my_str;
        return answer;
    }
}