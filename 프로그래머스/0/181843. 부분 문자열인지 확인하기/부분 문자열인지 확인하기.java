/*
부분 문자열 : 문자열에서 연속된 일부분에 해당하는 문자열 
ex )
문자열 ana, ban, anana, banana, n은 모두 문자열 banana의 부분 문자열이지만
aaa, bnana, wxyz는 모두 banana의 부분 문자열이 아니다.

매개변수 : my_string, target
문자열 target이 문자열 my_string의 부분 문자열이라면 1 아니면 0 return 
--> HOW?
contains() 함수 사용?
*/
class Solution {
    public int solution(String my_string, String target) {
        int answer = 0;
        if(my_string.contains(target)) answer = 1;
        return answer;
    }
}