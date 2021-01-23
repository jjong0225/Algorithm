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
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
    return 0;
}

bool checker[1004] = {0};


int main ()
{
    int count = 0;
    cin >> count;
    for(int counter=0; counter<count; counter++)
    {
        vector<pair<int,int>> input_v;
        memset(checker, 0, sizeof(checker));
        int N, M, output = 0;
        cin >> N >> M;
        for(int i=0; i<M; i++)
        {
            int a,b;
            cin >> a >> b;
            input_v.push_back(make_pair(a,b));
        }
        sort(input_v.begin(), input_v.end(), my_compare);
        int output_max = 0;
        int now_idx = 0;
        for(int i=now_idx; i<M; i++)
        {
            for(int j=input_v[i].first; j<= input_v[i].second; j++)
            {
                if(checker[j] == 0)
                {
                    output_max++;
                    checker[j] = 1;
                    break;
                }
            }
        }
        cout << output_max << endl;
    }    return 0;
}