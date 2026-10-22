/*
문자열들이 담긴 리스트
모든 문자열들을 순서대로 합친 문자열을 꼬리 문자열
꼬리 문자열을 만들 때 특정 문자열을 포함한 문자열은 제외하려 한다.
ex )
문자열 리스트 ["abc", "def", "ghi"]가 있고 문자열 "ef"를 포함한 문자열은 제외하고 만드려 한다.
-> abcghi

문자열 리스트 str_list와 제외하려는 문자열 ex가 주어질 때, str_list에서 ex를 포함한 문자열을 제외하고 만든
꼬리 문자열 return

-> HOW?

contains함수 이용해서 포함하면 그 인덱스에 있는 문자열은 x
*/
class Solution {
    public String solution(String[] str_list, String ex) {
        String answer = "";
        for(int i=0; i<str_list.length; i++){
            if(!str_list[i].contains(ex)) answer += str_list[i];
        }
        return answer;
    }
}