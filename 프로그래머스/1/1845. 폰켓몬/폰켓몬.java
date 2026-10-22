import java.util.*;

class Solution {
    public int solution(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<nums.length; i++) {
            Integer n = nums[i];
            map.put(nums[i], map.getOrDefault(n, 0) + 1);
        }
        int size = map.size(); // 종류 수
        int n = nums.length; // 총 개수
        
        return Math.min(size, n/2);
    }
}