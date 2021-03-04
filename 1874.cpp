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
    stack<int> s;
    int now_num = 1;
    string output_str;
    for(int i=1; i<=n; i++)
    {
        int abc;
        cin >> abc;
        while(s.empty() || s.top() != abc)
        {
            s.push(now_num++);
            output_str.push_back('+');
            if(now_num > n+1)
            {
                cout << "NO";
                return;
            }
        }
        s.pop();
        output_str.push_back('-');
    }
    for(int i=0; i<output_str.length(); i++)
        cout << output_str[i] << '\n';
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}