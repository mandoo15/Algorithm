/*
머쓱이 할머니 생신 축하 편지
글자 한 글자당 가로 2cm크기, 편지를 가로로만 적음.
message를 적기 위해 필요한 편지지의 최소 가로길이?
공백도 하나의 문자로 취급
글자 하나당 2라고 했으니, message의 길이를 찾아서 *2하면 됨.
*/
class Solution {
    public int solution(String message) {
        int answer = message.length() * 2;
        return answer;
    }
}