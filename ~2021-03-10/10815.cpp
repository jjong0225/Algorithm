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
int input_a[500001] = {0};
void solution()
{
    // code
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        input_a[i] = tmp;
    }
    sort(input_a, input_a+n+1);
    int m;
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int tmp;
        cin >> tmp;
        if(binary_search(input_a, input_a+n+1, tmp))
            cout << "1 ";
        else
            cout << "0 ";
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