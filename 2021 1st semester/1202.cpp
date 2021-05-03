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
#include<list>

#include<algorithm>
#include<math.h>
#include<climits> // 자료형 limit포함


using namespace std;

typedef long long int lld;

bool jewelry_cmp(pair<int,int>a, pair<int,int>b)
{
    return a.second > b.second;
}

void solution()
{
    int N,K; // 1 ≤ N, K ≤ 300,000
    cin >> N >> K;
    vector<pair<int,int>> jewelry;
    list<int> bag;

    for(int i=0; i<N; i++)
    {
        int tmp_1, tmp_2 = 0;
        cin >> tmp_1 >> tmp_2;
        jewelry.push_back(make_pair(tmp_1, tmp_2));
    }
    for(int i=0; i<K; i++)
    {
        int tmp_1 = 0;
        cin >> tmp_1;
        bag.push_back(tmp_1);
    }
    sort(jewelry.begin(), jewelry.end(), jewelry_cmp);
    bag.sort(less<int>());
    int output = 0;
    
    int bag_counter = 0;
    for(int i=0; i<N; i++)
    {
        list<int>::iterator tmp_it;
        tmp_it = lower_bound(bag.begin(), bag.end(), jewelry[i].first);
        if(tmp_it != bag.end())
        {
            output += jewelry[i].second;
            tmp_it = bag.erase(tmp_it);
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