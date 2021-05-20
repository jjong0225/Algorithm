#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int i=0;
    int answer = 0;
    vector<string> tmp_v = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while(i<s.length())
    {
        if(s[i] <= '9' && s[i] >= '0')
        {
            answer = answer * 10 + (s[i]-'0');
            i++;            
        }
        else
        {
            for(int k=0; k<10; k++)
            {
                if(!s.compare(i, tmp_v[k].length(), tmp_v[k]))
                {
                    answer = answer * 10 + k;
                    i+= tmp_v[k].length();
                    break;
                }
            }
        }
    }
    return answer;
}