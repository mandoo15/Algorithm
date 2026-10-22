class Solution {
    public int solution(int[][] sizes) {
        for(int i=0; i<sizes.length; i++) {
            int a = sizes[i][0], b = sizes[i][1];
            
            if (a < b) {
                sizes[i][0] = b;
                sizes[i][1] = a;
            }
        }
        int w = 0, h = 0;
        for(int i=0; i<sizes.length; i++) {
            if(sizes[i][0] > w) w = sizes[i][0];
            if(sizes[i][1] > h) h = sizes[i][1];
        }
        int answer = w * h;
        return answer;
    }
}