/*
문자열 my_string과 정수 배열 index_list가 매개변수
my_string의 index_list의 원소들에 해당하는 인덱스의 글자들을 순서대로 이어붙인 문자열 return

-> substring
*/
class Solution {
    public String solution(String my_string, int[] index_list) {
        String answer = "";
        for(int i=0; i<index_list.length; i++){
            answer += my_string.substring(index_list[i], index_list[i]+1);
        }
        return answer;
    }
}