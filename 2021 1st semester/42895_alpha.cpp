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

int count_arr[10000000] = {0};
lld output = MY_INT_MAX;
vector<vector<lld>> dp;

int get_n_k(int k, int n)
{
    int return_val = n;
    for(int i=1; i<k; i++)
        return_val = return_val * 10 + n;
    return return_val;
}

int solution(int n, int number, int k)
{
    if(k>8 || number >= 10000000 || number <= 0)
        return MY_INT_MAX;
    if(count_arr[number] != 0)
        return count_arr[number];
    int output = MY_INT_MAX;
    for(int i=1; i<100; i++)
    {
        int tmp_1 = MY_INT_MAX;
        int tmp_2 = MY_INT_MAX;
        int tmp_3 = MY_INT_MAX;
        int tmp_4 = MY_INT_MAX;
        if(i != number)
        {
            tmp_1 = solution(n, i, k+1) + solution(n, number-i, k+1);
            // tmp_2 = solution(n, i, k+1) + solution(n, number+i, k+1);
            // tmp_4 = solution(n, i, k+1) + solution(n, number/i, k+1);
        }
        // if(i != 1)
        // {
        //     tmp_3 = solution(n, i, k+1) + solution(n, number*i, k+1);
        // }
        output = min(output,min(tmp_1,min(tmp_2,min(tmp_3,tmp_4))));
    }
    count_arr[number] = output;
    return count_arr[number];
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    int a,b;
    cin >> a >> b;
    for(int i=1; i<=6; i++)
    {
        count_arr[get_n_k(i,a)] = i;
    }
    count_arr[1] = 2;
    count_arr[11] = 3;
    
    cout << solution(a,b, 0);
    cout << "ff";
    return 0;
}