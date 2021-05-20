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
    lld n, l;
    cin >> n >> l;
    lld start_val = -1;

    while(l <= 100)
    {
        if((2*n - l*(l-1)) % (2*l) == 0)
        {
            start_val = (2*n - l*(l-1)) / (2*l);
            break;
        }
        else
            l++;
    }
    if(l > 100 ||  start_val <= -1 || l*(start_val+(start_val+l-1))/2 < n)
        cout << "-1";
    else
    {
        for(int i=0; i<l; i++)
            cout << start_val + i << " ";
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