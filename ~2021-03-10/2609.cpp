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

int my_gcd(int a, int b)
{
    if(a-b == 0)
        return a;
    else
    {
        int tmp_max = max(a,b);
        int tmp_min = min(a,b);
        return my_gcd(tmp_max-tmp_min, tmp_min);
    }
}

void solution()
{
    int m,n;
    cin >> m >> n;
    int my_gcd_v = my_gcd(m,n);
    cout << my_gcd_v << "\n";
    cout << m * n / my_gcd_v;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}