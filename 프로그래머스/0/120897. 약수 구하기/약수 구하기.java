/*
정수 n이 매개변수로 주어질 때, n의 약수를 오름차순으로 담은 배열 return
-> for문
*/
class Solution {
    public int[] solution(int n) {
        int[] arr = new int[n];
        int x = 0;
        for(int i=1; i<n+1; i++){
            if(n%i==0) {
                arr[x] = i;
                x++;
            }
        }
        int[] answer = new int[x];
        for(int i=0; i<x; i++){
            answer[i] = arr[i];
        }
        return answer;
    }
}