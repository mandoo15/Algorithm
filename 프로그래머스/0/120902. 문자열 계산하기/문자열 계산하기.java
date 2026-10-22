class Solution {
    public int solution(String my_string) {
        String[] str = my_string.split(" ");
        // 공백 제거 배열로 생성
        int answer = Integer.parseInt(str[0]); // 초기값

        for (int i = 1; i < str.length; i += 2) {
            String operator = str[i]; // 연산자
            int number = Integer.parseInt(str[i+1]); // 다음 숫자

            switch (operator) {
                case "+":
                    answer += number; // answer에 숫자를 더함
                    break;
                case "-":
                    answer -= number; // answer에서 숫자를 뺌
                    break;
            }
        }
        return answer;
    }
}