/*
문자열 s가 매개변수
s에서 한 번만 등장하는 문자를 사전순으로 정렬한 문자열 return
*/
import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        Map<Character, Integer> map = new HashMap<>(); 
        
        // 각 문자의 등장 횟수 세기
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        
        // 한 번만 등장하는 문자들을 저장할 리스트 !!!!!!
        List<Character> singleChars = new ArrayList<>();
        
        // 맵을 순회하며 한 번만 등장하는 문자 찾기 
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            if (entry.getValue() == 1) {
                singleChars.add(entry.getKey());
            }
        }
        
        // 정렬 !!!
        Collections.sort(singleChars);
        
        // 정렬된 문자들을 문자열로 합치기
        StringBuilder sb = new StringBuilder();
        for (char c : singleChars) {
            sb.append(c);
        }
        
        answer = sb.toString();
        
        return answer;
    }
}