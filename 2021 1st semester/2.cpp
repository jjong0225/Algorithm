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
    int n;
    cin >> n;
    int prev[2] = {0};
    cin >> prev[0] >> prev[1];
    for(int i=0; i<n-1; i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int tmp_a = 0, tmp_b = 0;
        tmp_a = min(prev[0], prev[1]+b) + c;
        tmp_b = min(prev[1], prev[0]+a) + d;
        prev[0] = tmp_a;
        prev[1] = tmp_b;
    }
    cout << min(prev[0], prev[1]);
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}