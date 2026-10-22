/* 문자열 strArr, 원소들을 길이가 같은 문자열들끼리 그룹으로 믂었을 때 개수가 많은 그룹 크기 return */
class Solution {
    public int solution(String[] strArr) {
        int[] cnt = new int[31];
        int answer = 0;
        for(int i=0; i<strArr.length; i++){
            int x = strArr[i].length();
            cnt[x]++;
        }
        
        for(int i=0; i<31; i++){
            if(cnt[i]>answer) answer = cnt[i];
        }
        return answer;
    }
}