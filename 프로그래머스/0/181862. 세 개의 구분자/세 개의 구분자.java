/* 임의의 문자열 -> a, b, c를 구분자로 사용해 문자열 나눔.
baconlettucetomato ( example ) -> 
*/

import java.util.ArrayList;
import java.util.List;
class Solution {
    public String[] solution(String myStr) {
        String[] parts = myStr.split("[abc]"); // 정규표현식
        
        // 빈 문자열 제거
        List<String> result = new ArrayList<>();
        for (String part : parts) {
            if (!part.isEmpty()) {
                result.add(part);
            }
        }

        // 결과가 비어 있으면 "EMPTY" 반환
        if (result.isEmpty()) {
            return new String[] {"EMPTY"};
        }

        return result.toArray(new String[0]);
    }
}