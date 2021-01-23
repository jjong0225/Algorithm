#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
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

void solution()
{
    int n = 0;
    cin >> n;
    int a, b = 0;
    a = n/10;
    b = n%10;
    int count = 0;
    while(1)
    {
        int tmp = (a+b) % 10;
        a = b;
        b = tmp;
        count++;
        if(a * 10 + b == n)
            break;
    }
    cout << count;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}