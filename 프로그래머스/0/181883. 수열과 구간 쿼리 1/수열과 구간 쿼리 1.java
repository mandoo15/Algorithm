class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        int[] answer = new int[arr.length];
        int col = queries[0].length;
        
        for(int i=0; i<queries.length; i++){ // 행 길이
            for(int j=queries[i][0]; j<queries[i][col-1]+1; j++){
                arr[j] += 1;
            }
        }
        
        for(int i=0; i<arr.length; i++){
            answer[i] = arr[i];
        }
        return answer;
    }
}