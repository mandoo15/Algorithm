//included[i] = i+1항 , true인 항들만 더해.
class Solution {
    public int solution(int a, int d, boolean[] included) {
        int answer = 0;
        for(int i=0; i<included.length; i++){
            if(included[i] == true){
                answer += (a + i*d);
            }
        }
        return answer;
    }
}