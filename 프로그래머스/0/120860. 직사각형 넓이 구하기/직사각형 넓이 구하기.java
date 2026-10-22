/*
2차원 배열 -> 4꼭짓점이 x,y 형태로 담겨 있음 dots
직사각형 넓이 || x값이 같은 부분을 찾아서 y2-y1 * y값이 같은 부분을 찾아서 x2-x1
y값 따로 저장
x값 따로 저장
*/

import java.util.*;

class Solution {
    public int solution(int[][] dots) {
        int[] xs = new int[4];
        int[] ys = new int[4];
        
        for(int i=0; i<dots.length; i++){
            xs[i] = dots[i][0];
            ys[i] = dots[i][1];
        }
        
        Arrays.sort(xs);
        Arrays.sort(ys);
        
        return (xs[2]-xs[0])*(ys[2]-ys[0]);
    }
}