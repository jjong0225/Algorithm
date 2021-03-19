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
	for(int i=0; i<n; i++)
	{
		lld a,b,c,d,output = 0;
		cin >> a >> b;
        c = a / 5;
        d = b / 7;
        if(c <= d)
            cout << c << "\n";
        else // c > d
        {
            a = a - d*5;
            b = b - d*7;
            a = a + b;
            cout << d + a/12 << "\n";
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