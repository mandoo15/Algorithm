/*
정수 리스트 num_list
가장 첫 번째 원소를 1번 원소
홀수번째 원소들의 합과 짝수번째 원소들의 합 중 큰 값을 return
-> HOW?
인덱스 기준으로 짝수 : 홀수번째 원소
인덱스 기준으로 홀수 : 짝수번째 원소
for문 2개로 짝, 홀 합 구하기
비교 -> return
*/
class Solution {
    public int solution(int[] num_list) {
        int answer = 0, odd = 0, even = 0;
        
        for(int i=0; i<num_list.length; i+=2){ // odd
            odd += num_list[i];
        }
        
        for(int i=1; i<num_list.length; i+=2){ // even
            even += num_list[i];
        }
        
        if(odd>even) answer = odd;
        if(even>odd) answer = even;
        if(even == odd) answer = odd;
        return answer;
    }
}