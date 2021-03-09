// 내 코드
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for(int i=1; i<= n; i++)
    {
        if(i%2 == 1)
            answer += "수";
        else
            answer += "박";
    }
    return answer;
}


// 다른 사람의 코드
/*
&연산자 (비트연산자)를 이용한 홀/짝 판별
? 연산자를 이용한 코드 간결화
*/
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for(int i = 0; i < n; i++)
        i & 1 ? answer += "박" : answer += "수";

    return answer;
}
