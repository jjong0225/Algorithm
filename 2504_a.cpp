#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<stack>
#include<queue> // priority_queue 포함
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>

#include<algorithm>
#include<math.h>
#include<climits> // 자료형 limit포함

using namespace std;

typedef long long int lld;
typedef unsigned long long int uld;
typedef unsigned int ui;

const int MY_INT_MAX = 2000000000;

void solution()
{
    // code
    stack<char> s;
    string input_str;
    cin >> input_str;
    int answer, tmp = 0;
    tmp = 1;
    int flag = 0;
    for(int i=0; i<input_str.length(); i++)
    {
        if(input_str[i] == '(')
        {
            tmp *= 2;
            s.push('(');
        }
        else if(input_str[i] == '[')
        {
            tmp *= 3;    
            s.push('[');
        }
        else if (input_str[i] == ')' && (s.empty() || s.top() != '('))
        {
            flag = 1;
            break;
        }
        else if (input_str[i] == ']' && (s.empty() || s.top() != '['))
        {
            flag = true;
            break;
        }
        else if(input_str[i] == ')')
        {
            if(s.empty())
            {
                flag = 1;
                break;
            }
            if(s.top() =='(')
            {
                if(i > 0 && input_str[i-1] == '(')
                    answer += tmp; 
                tmp /= 2;
                s.pop();
            }
            else
            {
                flag = 1;
                break;
            }
        }
        else if(input_str[i] == ']')
        {
            if(s.empty())
            {
                flag = 1;
                break;
            }
            if(s.top() == '[')
            {
                if(i > 0 && input_str[i-1] == '[')
                    answer += tmp; 
                tmp /= 3;    
                s.pop();
            }
            else
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1)
    {
        cout << 0;
        return;
    }
    else
    {
        if(s.empty())
            cout << answer;
        else
            cout << 0;
    }
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}