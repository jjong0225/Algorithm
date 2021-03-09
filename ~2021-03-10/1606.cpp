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

void solution()
{
    // code
    int a,b =0;
    cin >> a >> b;
    int num_of_shell = 0;
    if(a * b < 0)
    {
        if(abs(a) > abs(b))
        {
            num_of_shell += abs(b);
            num_of_shell += (abs(a) - abs(b));
        }
        else
        {
            num_of_shell += abs(a);
            num_of_shell += abs(abs(b) - abs(a));
        }
    }
    else
    {
        num_of_shell += abs(a) + abs(b);
    }
    if(num_of_shell == 0)
    {
        cout << 1;
        return;
    }


    lld now_num = 0;
    for(int i=1; i< num_of_shell; i++)
        now_num = now_num + 6*i;

    for(int i=0; i<=0; i++)
    {
        if(a >= 0 && a< num_of_shell && b > 0 && b <=num_of_shell)
        {
            now_num = now_num + b;
            continue;
        }
        else
            now_num += num_of_shell;
        if(b==num_of_shell && a < 0)
        {
            now_num = now_num + abs(a);
            continue;
        }
        else
            now_num = now_num + num_of_shell;
        if(a == -1 * num_of_shell && b >= 0 && b < num_of_shell)
        {
            now_num = now_num + (num_of_shell-b);
            continue;
        }
        else
            now_num = now_num + num_of_shell;
        if(a <= 0 && b < 0)
        {
            now_num = now_num + abs(b);
            continue;
        }
        else
            now_num = now_num + num_of_shell;
        if(a>0 && b == -1*num_of_shell)
        {
            now_num = now_num + a;
            continue;
        }
        else
            now_num = now_num + num_of_shell;
        if(a == num_of_shell && b <= 0)
        {
            now_num = now_num + abs(num_of_shell-b);
            continue;
        }
        else
            now_num = now_num + num_of_shell;
    }
    cout << now_num+1;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}