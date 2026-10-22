/*
두 정수 배열의 대소관계
- 두 배열의 길이가 다르다면 배열의 길이가 긴 쪽이 크다.
- 배열의 길이가 같다면 각 배열에 있는 모든 원소의 합을 비교해 더 큰 쪽이 크고, 같다면 같다.

arr1, arr2 배열 매개변수
arr2가 크면 -1, arr1이 크면 1, 같다면 0 return
--> HOW?
1. arr1과 arr2의 길이를 비교해 같다면, 다르다면 : 이중 if문
2. 같다면 - 각 원소의 합 비교 ( 큰지, 작은지, 같은지 ) : for문과 if문 이용
*/
class Solution {
    public int solution(int[] arr1, int[] arr2) {
        int answer = 0, sum1 = 0, sum2 = 0;
        if(arr1.length == arr2.length ){
            for(int i=0; i<arr1.length; i++){ // 둘의 길이가 같음
                sum1 += arr1[i];
                sum2 += arr2[i];
            }
            if(sum1 > sum2) answer = 1;
            if(sum1 < sum2) answer = -1;
        }
        if(arr1.length > arr2.length) answer = 1;
        if(arr2.length > arr1.length) answer = -1;
        return answer;
    }
}