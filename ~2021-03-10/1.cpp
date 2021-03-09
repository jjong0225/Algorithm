#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0; i<s.length(); i++)
    {
        if(s.at(i) >= 'a' && s.at(i) <= 'z')
        {
            char tmp = s.at(i) - 'a';
            tmp = ((tmp+n) % 26) + 'a';
            answer += tmp;
        }
        else if(s.at(i) >= 'A' && s.at(i) <= 'Z')
        {
            char tmp = s.at(i) - 'A';
            tmp = ((tmp+n) % 26) + 'A';
            answer += tmp;
        }
        else
        {
            answer += s.at(i);
        }
    }
    return answer;
}

int main ()
{
    cout << solution("abc",1 );
}