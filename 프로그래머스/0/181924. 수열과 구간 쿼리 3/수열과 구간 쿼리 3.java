/*
    정수 배열 arr / 2차원 정수 배열 queries
    queries 원소 : 각각 하나의 query, [i, j]꼴
    각 query마다 순서대로 arr[i]의 값과 arr[j]의 값을 서로 바꿉니다.
    
    queries 처리 후 arr return
*/
class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        for (int i = 0; i < queries.length; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            int temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
        }
        return arr;
    }
}