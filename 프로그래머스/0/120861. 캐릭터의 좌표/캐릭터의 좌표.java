/*
방향키 : up, down, left, right
ex [0,0] : [0,1] [0,-1] [-1,0] [1,0]

키 입력이 모두 끝난 뒤의 좌표를 return
*/

class Solution {
    public int[] solution(String[] keyinput, int[] board) {
        int[] answer = {0,0};
        for(int i=0; i<keyinput.length; i++){
            String s = keyinput[i];
            switch(s) {
                case "up":
                    if(answer[1] < (board[1]-1)/2) answer[1]++;
                    break;
                case "down":
                    if(answer[1] > -1*(board[1]-1)/2) answer[1]--;
                    break;
                case "left":
                    if(answer[0] > -1*(board[0]-1)/2) answer[0]--;
                    break;
                case "right":
                    if(answer[0] < (board[0]-1)/2) answer[0]++;
                    break;
            }
        }
        return answer;
    }
}