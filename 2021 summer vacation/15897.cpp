#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<list>
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
    lld n;
    cin >> n;
    lld result = 0;
    lld now_val = n;
    while(1)
    {
        if(now_val == 0)
            break;
        lld num_count = ((n-1) / now_val) + 1;
        lld next_val = ceil((double)n / num_count) - 1;
        result += num_count * (now_val - next_val);
        now_val = next_val;
    }
    cout << result;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}