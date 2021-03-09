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
typedef unsigned long long int uld;

void solution()
{
    // code
    int n;
    cin >> n;
    vector<int> dist_v;
    vector<int> station_v;
    for(int i=0; i<n-1; i++)
    {
        int tmp;
        cin >> tmp;
        dist_v.push_back(tmp);
    }
    for(int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        station_v.push_back(tmp);
    }
    uld min_price = 1000000001;
    uld output = 0;
    for(int i=0; i<n-1; i++)
    {
        if(min_price > station_v[i])
            min_price = station_v[i];
        output += min_price*dist_v[i];
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