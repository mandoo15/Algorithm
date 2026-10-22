/*
정수 배열 arr 정수 n 매개변수
arr의 길이가 홀수라면 - arr의 모든 짝수 인덱스 위치에 n을 더한 배열
arr의 길이가 짝수라면 - arr의 모든 홀수 인덱스 위치에 n을 더한 배열을 return
--> HOW?
if문으로 홀 짝 확인 후 for문으로 짝수, 홀수 번호에만 n을 더한다.
*/
class Solution {
    public int[] solution(int[] arr, int n) {
        if(arr.length%2==0){
            for(int i=1; i<arr.length; i+=2){
                arr[i] += n;
            }
        }
        if(arr.length%2==1){
            for(int i=0; i<arr.length; i+=2){
                arr[i] += n;
            }
        }
        return arr;
    }
}