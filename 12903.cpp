// 내 코드
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int even_flag = 0;
    if(s.length()%2 == 0)
        even_flag = 1;
    if(even_flag == 0)
    {
        answer += s.at(s.length()/2);        
    }
    else
    {
        answer += s.at((s.length()/2) - 1);
        answer += s.at(s.length()/2);
    }
    
    return answer;
}

// 배울만한 타인의 코드
/*
substr이용
?연산 이용
*/

#include <string>

using namespace std;

string solution(string s) {
    return s.length()&1 ? s.substr(s.length()*0.5,1) : s.substr(s.length()*0.5-1,2);
}