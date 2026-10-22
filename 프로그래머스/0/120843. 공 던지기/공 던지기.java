/*
공은 1번부터 던지며 오른쪽으로 한 명을 건너뛰고 그 다음 사람에게만 던질 수 있음
친구들의 번호가 들어있는 정수 배열 numbers
정수 k
k번째로 공을 던지는 사람의 번호?
*/
class Solution {
    public int solution(int[] numbers, int k) {
        int answer = 0, ind = 0;
        for(int i=0; i<k; i++){
            answer = numbers[ind];
            ind += 2;
            if(ind > numbers.length-1) {
                ind -= numbers.length;
            } 
        }
        return answer;
    }
}