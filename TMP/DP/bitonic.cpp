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
    return hi;
}

void solution()
{
    // code
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int tmp_int;
        cin >> tmp_int;
        input_v.push_back(tmp_int);
    }
    DP.push_back(0);
    int now_max = -1;
    for(int i=0; i<input_v.size(); i++)
    {
        if(DP[DP.size()-1] < input_v[i])
        {
            DP.push_back(input_v[i]);

            vector<int> DP_2;
            DP_2.push_back(input_v[i]);
            int now_val = 0;
            for(int j=i+1; j<input_v.size(); j++)
            {
                if(DP_2[now_val] > input_v[j])
                {
                    DP_2.push_back(input_v[j]);
                    now_val++;
                }
                else
                {
                    int cmp_idx = lower_bound(DP_2.begin(), DP_2.end(), input_v[j], greater<int>()) - DP_2.begin(); 
                    DP_2[cmp_idx] = input_v[j];
                }
            }
            now_max = max(now_max, (int)(DP.size()-1 + now_val));
        }
        else
        {
            int cmp_idx = binary_search(input_v[i]); 
            DP[cmp_idx] = input_v[i];
        }
    }
    cout << now_max;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}