function solution(my_string, s, e) {
    var answer = '';
    answer = my_string.substring(0, s);
    for(let i=e; i>=s; i--){
            answer += my_string.charAt(i);
        }
    answer += my_string.substring(e+1, my_string.length);
    
    return answer;
}