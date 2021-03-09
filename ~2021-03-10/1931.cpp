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

bool my_comp(pair<int,int>a, pair<int,int>b)
{
    if(a.second < b.second)
        return 1;
    else if (a.second > b.second)
        return 0;
    else if(a.second == b.second)
    {
        if(a.first <= b.first)
            return 1;
        else
            return 0;
    }
    return 0;
}

void solution()
{
    // code
    int N = 0;
    cin >> N;
    vector<pair<int,int>> input_arr;
    for(int i=0; i<N; i++)
    {
        int a,b =0 ;
        cin >> a >> b;
        input_arr.push_back(make_pair(a,b));
    }
    sort(input_arr.begin(),input_arr.end(),my_comp);
    int now_end_time = input_arr[0].second;
    int output = 1;
    for(int i=1; i<input_arr.size(); i++)
    {
        if(now_end_time <= input_arr[i].first)
        {
            output++;
            now_end_time = input_arr[i].second;
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