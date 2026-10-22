/*
알파벳이 담긴 배열 spell
외계어 사전 dic

spell에 담긴 알파벳을 "한 번씩만" 모두 사용한 단어가 dic에 존재 O - 1, X - 2
*/
class Solution {
    public int solution(String[] spell, String[] dic) {
        int answer = 2;
        int cnt = 0;
        for(int i=0; i<dic.length; i++){ // dic 길이만큼
            cnt=0;
            for(int j=0; j<spell.length; j++){
                if(dic[i].contains(spell[j])) {
                    int orilen = dic[i].length();
                    dic[i] = dic[i].replaceAll(spell[j], "");
                    int newlen = dic[i].length();
                    if(orilen-newlen == 1) cnt++;
                }
            }
            if(cnt==spell.length) {
                answer = 1;
                break;
            }
        }
        return answer;
    }
}