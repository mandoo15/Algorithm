/*
정수 배열 array 매개변수
가장 큰 수와 그 수의 인덱스를 담은 배열을 return 
ex )
array [1, 8, 3] return [8, 1]
--> HOW?
for문을 이용해 max보다 크면 max값 변경, 인덱스 저장.*/
class Solution {
    public int[] solution(int[] array) {
        int[] answer = {0, 0};
        for(int i=0; i<array.length; i++){
            if(array[i] > answer[0]){
                answer[0] = array[i];
                answer[1] = i;
            }
        }
        return answer;
    }
}