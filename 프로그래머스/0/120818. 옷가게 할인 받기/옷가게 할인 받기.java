class Solution {
    public int solution(int price) {
        int answer = price;
        if(price>=100000 && price<300000) {
            answer -= answer*0.05;
            answer = (int)(Math.floor(answer));
        }
        if(price>=300000 && price<500000) {
            answer -= answer*0.1;
            answer = (int)(Math.floor(answer));
        } 
        if(price>=500000) {
            answer -= answer*0.2;
            answer = (int)(Math.floor(answer));
        }
        return answer;
    }
}