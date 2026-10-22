/*
어떤 문자열에 대해 접두사 : 특정 인덱스까지의 문자열
ex ) "banana"의 모든 접두사
b \ ba \ ban \ bana \ banan \ banana

문자열 my_string과 is_prefix가 주어질 때,
is_prefix가 my_string의 접두사라면 1 아니면 0 return

-> substring 이용 
*/
class Solution {
    public int solution(String my_string, String is_prefix) {
        int answer = 0;
        int index = is_prefix.length();
        String s = is_prefix;
        if(index > my_string.length()) answer = 0;
        else {
            s = my_string.substring(0, index);
        if(s.equals(is_prefix)) answer = 1;
        }
        
        return answer;
    }
}