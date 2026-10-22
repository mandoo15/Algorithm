class Solution {
    public String solution(String s) { // String형
        String[] arrs = s.split(" "); 
        int[] arri = new int[arrs.length];
        
        for(int i=0; i<arri.length; i++){
            arri[i] = Integer.parseInt(arrs[i]);  
        }
        
        int max = arri[0];
        int min = arri[0];
        
        for(int i=0; i<arri.length; i++){
            if(arri[i] < min) min = arri[i];
            if(arri[i] > max) max = arri[i];
        }
        
        return min + " " + max;
    }
}