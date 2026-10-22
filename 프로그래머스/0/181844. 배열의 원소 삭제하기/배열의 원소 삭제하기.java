/*
arr의 원소 중 delete_list의 원소를 모두 삭제하고 남은 원소들은 기존 arr에 있던 순서를 유지한 배열을 return

*/

class Solution {
    public int[] solution(int[] arr, int[] delete_list) {
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<delete_list.length; j++){
                if(arr[i] == delete_list[j]){
                    arr[i] = 0;
                }
            }
        }
        
        int cnt = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i]!=0) cnt++;
        }
        
        int[] answer = new int[cnt];
        cnt = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i]!=0){
                answer[cnt] = arr[i];
                cnt++;
            }
        }
        return answer;
    }
}