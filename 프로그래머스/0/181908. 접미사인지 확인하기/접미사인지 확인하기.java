/*
접미사 - 특정 인덱스부터 시작하는 문자열
ex ) banana의 모든 접미사
banana \ anana \ nana \ ana \ na \ a
문자열 my_string과 is_suffix가 주어질 때
is_suffix가 my_string의 접미사라면 1 아니면 0 return

-> HOW?
시작하는 인덱스 위치가 다 다름 but 끝나는 위치는 똑같다.
substring
*/
class Solution {
    public int solution(String my_string, String is_suffix) {
        int answer = 0;
        int index = is_suffix.length()-1;
        
        if(index < my_string.length()){
            int my = my_string.length(); 
            String s = my_string.substring(my - index -1, my);
            System.out.println(s);
            if(s.equals(is_suffix)) answer = 1;
        }
        return answer;
    }
}