/*
정수 배열 arr
2차원 정수 배열 queries -> 원소는 각각 하나의 query [s, e, k] 형태

s<=i<=e인 모든 i에서 i가 k의 배수이면 arr[i]에 1을 더한다
*/
class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        for(int i=0; i<queries.length; i++) {
            for(int j=queries[i][0]; j<=queries[i][1]; j++){
                if(j%queries[i][2]==0) {
                    arr[j]+=1;
                }
            }
        }
        return arr;
    }
}