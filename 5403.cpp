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
    int num_of_test;
    cin >> num_of_test;
    for(int count = 0; count < num_of_test; count++)
    {
        string command_str;
        cin >> command_str;
        int n;
        cin >> n;
        deque<int> dq;
        for(int i=0; i<n; i++)
        {
            char dummy;
            int input_d;
            cin >> dummy >> input_d;
            dq.push_back(input_d);
        }
        if(n == 0)
        {
            char dummy;
            cin >> dummy;
        }
        char dummy;
        cin >> dummy;
        bool is_inverted = 0;
        bool flag = 0;
        for(int i=0; i<command_str.length(); i++)
        {
            if(command_str[i] == 'R')
                is_inverted = !is_inverted;
            else if(command_str[i] == 'D')
            {
                if(dq.empty())
                {
                    flag = 1;
                    break;
                }
                if(is_inverted)
                    dq.pop_back();
                else if(!is_inverted)
                    dq.pop_front();
            }
        }
        if(flag)
            cout << "error";
        else
        {
            int tmp_count = dq.size();
            cout << "[";
            for(int i=0; i<tmp_count; i++)
            {
                if(is_inverted)
                {
                    cout << dq.back();
                    dq.pop_back();
                }
                else
                {
                    cout << dq.front();
                    dq.pop_front();
                }
                if(i < tmp_count-1)
                    cout << ",";
            }
            cout << "]";
        }
        cout << "\n";
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