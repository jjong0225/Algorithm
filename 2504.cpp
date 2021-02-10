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
    vector<int> v;
    v.push_back(10);  // 정적 vs 동적 
    cout << v[10];
    // code
    string input_str;
    cin >> input_str;
    stack<int> s;

    if(input_str[0] == '(')
        s.push(-1);
    else if(input_str[0] == '[')
        s.push(-2);
    else
    {
        cout << 0;
        return;
    }
    if(input_str.length()%2 == 1)
    {
        cout << 0;
        return;
    }

    for(int i=1; i<input_str.length(); i++)
    {
        char now_c = input_str[i];
        if(now_c == '(') // -1 = '(', -2 = '[', -3 = ')', -4 = ']'
            s.push(-1);
        else if (now_c == '[')
            s.push(-2);
        else
        {
            if(now_c == ')')
            {
                int now_top = 0;
                int tmp_sum = 0;
                while(1)
                {
                    if(now_top < 0 || s.empty())
                    {
                        cout << 0;
                        return;
                    }
                    now_top = s.top();
                    s.pop();
                    if(now_top == -1)
                    {
                        if(tmp_sum == 0)
                            s.push(2);
                        else
                            s.push(tmp_sum * 2);
                        break;
                    }
                    else if(now_top >= 0)
                        tmp_sum = tmp_sum + now_top;
                }
            }
            else if (now_c == ']')
            {
                int now_top = 0;
                int tmp_sum = 0;
                while(1)
                {
                    if(now_top < 0 || s.empty())
                    {
                        cout << 0;
                        return;
                    }
                    now_top = s.top();
                    s.pop();
                    if(now_top == -2)
                    {
                        if(tmp_sum == 0)
                            s.push(3);
                        else
                            s.push(tmp_sum * 3);
                        break;
                    }
                    else if(now_top >= 0)
                        tmp_sum = tmp_sum + now_top;
                }
            }
        }
    }
    int output = 0;
    while(!s.empty())
    {
        if(s.top() >= 0)
        {
           output += s.top();
           s.pop();
        }
        else
        {
            cout << 0;
            return;
        }

    }
    cout << output;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}