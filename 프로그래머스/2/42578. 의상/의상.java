/*
착용 의상 일부가 겹쳐도 다른 게 다르면 다른 방법으로 옷 입은 거임
하루에 최소 한 개의 의상을 입음
2차원 배열 clothes -> 서로 다른 옷의 조합의 수 return
[의상의 이름, 의상의 종류]
ex )
모자 모자 선글라스 -> 5가지 종류 모자, 모자, 선글라스, 모자 선글라스 모자 선글라스
마스크 마스크 마스크 -> 마스크

--> map에다가 넣어서 종류별로 
*/
import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        Map<String, Integer> map = new HashMap<>();
        
        for(int i=0; i<clothes.length; i++){
            String type = clothes[i][1];
            map.put(type, map.getOrDefault(type, 0) + 1);
        }
        
        int answer = 1;

        for (int count : map.values()) {
            answer *= (count + 1);
        }

        return answer - 1;
    }
}