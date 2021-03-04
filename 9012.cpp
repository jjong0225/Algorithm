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
    int n;
    cin >> n;
    for(int counter = 0; counter < n; counter++)
    {
        stack<char> s;
        string input_str;
        cin >> input_str;
        for(int i=0; i<input_str.length(); i++)
        {
            if(s.empty())
                s.push(input_str[i]);
            else
            {
                if(s.top() == '(' && input_str[i] == ')')
                    s.pop();
                else
                    s.push(input_str[i]);
            }
        }
        if(s.size() == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
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