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


/*
count번의 테스트 케이스

N권의 책 (1,000, 10^3)
학생 M명 (1,000, 10^3)

M명이 두개의 정수 a,b를 준다. ( a<=b )
a <= k <= b인 아무런 k번 책을 준다.

그렇다면 최대로 줄 수 있는 책의 수는?



*/
using namespace std;

typedef long long int lld;

bool my_compare (pair<int,int> a, pair<int,int> b)
{
    if (a.second-a.first > b.second-b.first)
        return 0;
    else if(a.second-a.first < b.second-b.first)
        return 1;
    else
    {
        if(a.first >= b.first)
            return 0;
        else
            return 1;
    }
}


void solution()
{
    // code
    int count = 0;
    cin >> count;
    for(int counter=0; counter<count; counter++)
    {
        int N, M, output = 0;
        cin >> N >> M;
        vector<int> num_of_reqeuset;
        vector<vector<int>> index_v;
        vector<pair<int,int>> input_v;
        vector<int> checker;
        for(int i=0; i<=N; i++)
        {
            vector<int>tmp_v;
            index_v.push_back(tmp_v);
            checker.push_back(-1);
            num_of_reqeuset.push_back(0);
        }
        for(int i=0; i<M; i++)
        {
            int a,b;
            cin >> a >> b;
            input_v.push_back(make_pair(a,b));
        }
        sort(input_v.begin(), input_v.end(), my_compare);
        for(int i=0; i<M; i++)
        {
            for(int now_idx=input_v[i].first; now_idx<=input_v[i].second; now_idx++)
            {
                num_of_reqeuset[now_idx]++;
                index_v[now_idx].push_back(i);
            }
        }


        for(int i=1; i<=N; i++)
        {
            int min_val = 1000000000;
            int min_pos = 1000000000;
            for(int j=1; j<=N; j++) // 최소 idx찾기
            {
                if(min_val > num_of_reqeuset[j] && num_of_reqeuset[j] > 0)
                {
                    min_val = num_of_reqeuset[j];
                    min_pos = j;
                }
            }
            if(min_pos == 1000000000)
                break;
            num_of_reqeuset[min_pos] = -1;

            pair<int,int> selected_pair;


            for(int w = 0; w<index_v[min_pos].size(); w++)
            {
                if(checker[index_v[min_pos][w]] != 1)
                {
                    selected_pair = input_v[index_v[min_pos][w]];
                    checker[index_v[min_pos][w]] = 1;
                }
            }
            if(selected_pair.first * selected_pair.second != 0)
                for(int w=selected_pair.first; w<=selected_pair.second; w++)
                {
                    --num_of_reqeuset[w];
                }
        }
        for(int i=1; i<=N; i++)
            if(num_of_reqeuset[i] < 0)
                output++;
        cout << output << '\n';
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