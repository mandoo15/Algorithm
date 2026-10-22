/*
1-13까지의 수에서 1은 1, 10, 11, 12, 13 이렇게 총 6번 등장한다.
정수 i, j, k가 매개변수로 주어질 때
i부터 j까지 k가 몇 번 등장하는지?
-> for문 조건 : i부터 k+1까지
string s = i; // 10 이상일 때부터
stirng[] str = s.split("");
for(int i=0; i<str.length; i++){
각
}*/
class Solution {
    public int solution(int i, int j, int k) {
        int answer = 0;
        for(int m=i; m<j+1; m++){
            String s = Integer.toString(m);
            String[] str = s.split("");
            for(int n=0; n<str.length; n++){
                if(str[n].contains(Integer.toString(k))){
                answer ++;
            }
            }
        }
        return answer;
    }
}