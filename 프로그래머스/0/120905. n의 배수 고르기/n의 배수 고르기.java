/*
정수 n과 정수 배열 numlist
numlist에서 n의 배수가 아닌 수들을 제거한 배열을 return
ex )
n 3
numlist [4, 5, 6, 7, 8, 9, 10, 11, 12]
result [6, 9, 12]
--> for문을 이용해 numlist길이만큼 반복, n으로 나눈 나머지가 0이면 answer에 저장.
*/
class Solution {
    public int[] solution(int n, int[] numlist) {
        int[] arr = new int[numlist.length];
        int cnt = 0;
        for(int i=0; i<numlist.length; i++){
            if(numlist[i]%n == 0) {
                arr[i] = numlist[i];
                cnt++;
            }
        }
        int[] answer = new int[cnt];
        cnt = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i] > 0) {
                answer[cnt] = arr[i];
                cnt++;
            }
            
        }
        return answer;
    }
}