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
    // code
    int N, K = 0;
    cin >> N >> K;
    vector<int> input_arr;
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        input_arr.push_back(tmp);
    }
    // a_n = a_n * k( k는 정수 )
    int output = 0;
    for(int i=input_arr.size()-1; i>=0; i--)
    {
        if(K - input_arr[i] >= 0)
        {
            int coin_num = K/input_arr[i];
            K = K - input_arr[i] * coin_num;
            output += coin_num;
        }
    }
    cout << output;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}