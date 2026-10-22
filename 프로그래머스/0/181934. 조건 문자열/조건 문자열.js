function solution(ineq, eq, n, m) {
    var answer = 0;

    switch(ineq){
        case ">":
            switch(eq){
                case "=":
                    if(n>=m) return 1;
                    else return 0;
                    break;
                case "!":
                    if(n>m) return 1;
                    else return 0;
                    break;
            }
            break;
        case "<":
            switch(eq){
                case "=":
                    if(n<=m) return 1;
                    else return 0;
                    break;
                case "!":
                    if(n<m) return 1;
                    else return 0;
                    break;
            }
            break;
    }
}