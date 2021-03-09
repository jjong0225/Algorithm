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
// 2차원 DP? : 10^6 -> 12ㄴㄴ
// 1+2+3....+10^6 -> 10^12 (대충), 1억 = 10^8 ㄴㄴ 
vector<int> DP;
vector<int> input_v;

int binary_search(int n)
{
    int hi = DP.size()-1;
    int low = 1;
    int mid = 0;
    while(hi > low)
    {
        mid = (hi+low)/2;
        if(n > DP[mid])
            low = mid+1;
        else if (n < DP[mid])
            hi = mid;
        else
            return mid;
    }
    // cout << low << " " << mid << " " << hi << endl;
    return hi;
}

void solution()
{
    // code
    int N;
    cin >> N;
    int max_num = 1000010;
    for(int i=0; i<N; i++)
    {
        int tmp_int;
        cin >> tmp_int;
        input_v.push_back(tmp_int);
    }
    DP.push_back(-1);
    for(int i=0; i<input_v.size(); i++)
    {
        if(DP[DP.size()-1] < input_v[i])
            DP.push_back(input_v[i]);
        else
        {
            int cmp_idx = binary_search(input_v[i]); 
            DP[cmp_idx] = input_v[i];
        }
        // for(int i=0; i<DP.size();i++)
        //     cout << DP[i] << " ";
        // cout << endl;
    }
    cout << DP.size()-1;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}