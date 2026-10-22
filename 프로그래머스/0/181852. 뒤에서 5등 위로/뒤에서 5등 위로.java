/*
정수로 이루어진 리스트 num_list
num_list에서 가장 작은 5개의 수를 제외한 수를 오름차순으로 담은 리스트 return
--> HOW?
num_list를 오름차순으로 정렬 후 index 5부터 num_list의 길이만큼 answer 정수형 배열에 저장.
*/
class Solution {
    public int[] solution(int[] num_list) {
        int[] answer = new int[num_list.length - 5];
        for(int i=0; i<num_list.length; i++){
            for(int j=0; j<num_list.length-1; j++){
                if(num_list[j] > num_list[j+1]){
                    int tmp = num_list[j+1];
                    num_list[j+1] = num_list[j];
                    num_list[j] = tmp;
                }
            }
        }
        int x = 0;
        for(int i=5; i<num_list.length; i++){
            answer[x] = num_list[i];
            x++;
        }
        return answer;
    }
}