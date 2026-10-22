/*
정수 배열 arr와 자연수 k가 주어짐.
만약 k가 홀수라면 arr의 모든 원소에 k를 곱해
만약 k가 짝수라면 arr의 모든 원소에 k를 더해
*/
class Solution {
    public int[] solution(int[] arr, int k) {
        int[] answer = new int[arr.length];
        if(k%2==1){
            for(int i=0; i<arr.length; i++){
                answer[i] = arr[i]*k;
            }
        }
        if(k%2==0){
            for(int i=0; i<arr.length; i++){
                answer[i] = arr[i]+k;
            }
        }
        return answer;
    }
}