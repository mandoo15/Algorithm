/*
논문 n편 중 h번 이상 인용된 논문이 h편 이상이고, 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 과학자의 h-index이다

배열 citations ( 논문의 인용횟수 ) -> h-index return

ex )
citations = [3, 0, 6, 1, 5] -> return 3
과학자가 발표한 논문의 수가 5편, 3편의 논문은 3회 이상 인용 but 나머지 2편은 3회 이하 인용 -> h-index : 3

citations의 길이가 발표한 논문의 수
오름차순 정렬 -> 중간값 기준으로 h 이상인 편 수 세어서 return
*/

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        for(int i=0; i<citations.length; i++){
            int compare = citations[i];
            int cnt = 0;
            for(int j=0; j<citations.length; j++){
                if(citations[j] >= compare) cnt++;
            }
            if(compare >= cnt && answer < cnt) {
                answer = cnt;
            }
        }
        return answer;
    }
}