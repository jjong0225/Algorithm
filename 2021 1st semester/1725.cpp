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

int dp_num[1000001] = {0}; // 10^6
int input_arr[100001] = {0};

void solution()
{
    // code
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> input_arr[i];
    for(int i=0; i< 1000; i++) // i^3
    {
        for(int j=0; j<100000; j++)
        {
            
        }
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