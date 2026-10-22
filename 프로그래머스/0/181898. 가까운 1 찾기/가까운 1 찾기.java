/*
정수 배열 arr
arr의 원소는 1 or 0
정수 idx가 주어졌을때 idx보다 크면서 배열의 값이 1인 가장 작은 인덱스?

*/
class Solution {
    public int solution(int[] arr, int idx) {
        int answer = -1;
        for(int i=idx; i<arr.length; i++){
            if(arr[i] == 1) {
                answer = i;
                break;
            }
        }
        return answer;
    }
}