#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue> // priority_queue 포함
#include<set>
#include<deque>
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
    string str;
    cin >> str;
    list<char> input_l;
    for(int i=0; i<str.length(); i++)
    {
        input_l.push_back(str[i]);
    }
    list<char>::iterator it = input_l.end();
    int m;
    cin >> m;
    for(int i=0; i<m; i++)
    {
        char input_c;
        cin >> input_c;
        if(input_c == 'L')
        {
            if(it != input_l.begin())
               it--;
        }
        else if(input_c == 'D')
        {
            if(it != input_l.end())
               it++;
        }
        else if(input_c == 'B')
        {
            if((it != input_l.begin()))
            {
                if(it == input_l.end())
                {
                    it--;
                    it = input_l.erase(it);
                }
                else
                {
                    it--;
                    it = input_l.erase(it);
                }
            }
        }
        else if(input_c == 'P')
        {
            char next_c;
            cin >> next_c;
            input_l.insert(it, next_c);
        }
    }
    for(list<char>::iterator it2 = input_l.begin(); it2 != input_l.end(); it2++)
        cout << *it2;    
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}