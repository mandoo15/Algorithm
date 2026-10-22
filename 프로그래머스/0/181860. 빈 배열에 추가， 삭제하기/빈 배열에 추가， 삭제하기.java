/*
아무 원소도 들어있지 않은 빈 배열 x
길이가 같은 정수 배열 arr, boolean 배열 flag 매개변수
flag를 차례대로 순회하며 
if flag[i]가 true, arr[i] = arr[i] x 2번 추가, 
if flag[i] false, x에서 마지막 arr[i]개의 원소 제거 후 x return

ex )
arr : 3, 2, 4, 1, 3 -> 3, 2, 4 -> 
flag : true, false, true, false, false
result : 3, 3, 3, 3, 4, 4, 4, 4

1. arr와 flag 길이 동일
2. for문 생성 | ArrayList t 생성
3. if flag[i]
4. false : for(int i=t.size()-1; i>t.size()-4; i--) 삭제
5. true : for(int i=t.size(); i<t.size()+arr[i]*2; i++) 추가

** 근데 문제에서 현재 x의 길이보다 더 많은 원소를 빼는 입력은 주어지지 않는다고 함. -> 즉, 처음은 항상 true라는 말씀.
*/
import java.util.*;

class Solution {
    public int[] solution(int[] arr, boolean[] flag) {
        ArrayList<Integer> t = new ArrayList<>();
        
        for(int i=0; i<arr.length; i++){
            if(flag[i] == true){
                int x = t.size(), y = arr[i];
                   for(int j=x; j<x+y*2; j++){
                    t.add(j, y);
                    }
            }
            if(flag[i] == false){
                int x = t.size()-1;
                for(int j=x; j>x-arr[i]; j--){
                    t.remove(j);
                }
            }
        }
        int x = t.size();
        int[] answer = new int[x];
        for(int i=0; i<answer.length; i++){
            answer[i] = t.get(i);
        }
        return answer;
    }
}