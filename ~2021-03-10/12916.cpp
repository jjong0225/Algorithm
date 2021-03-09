// 내 코드
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = false;
    int p_counter = 0;
    int y_counter = 0;
    
    for(int i=0; i<s.length(); i++)
    {
        if (s.at(i)=='P' ||  s.at(i)=='p')
            p_counter++;
        else if (s.at(i)=='Y' ||  s.at(i)=='y')
            y_counter++;
    }
    if(p_counter == y_counter)
        answer = true;

    return answer;
}

// 다른코드도 비슷