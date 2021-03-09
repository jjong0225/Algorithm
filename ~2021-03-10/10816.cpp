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

void solution()
{
    unordered_map<int,int> input_map;
    // code
    int n_1;
    cin >>n_1;
    for(int i=0; i<n_1; i++)
    {
        int tmp;
        cin >> tmp;
        if(input_map.find(tmp) == input_map.end())
            input_map.insert(make_pair(tmp,1));
        else
            (input_map.find(tmp)->second)++; 
    }
    int n_2;
    cin >> n_2;
    vector<int> idx_v;
    for(int i=0; i<n_2; i++)
    {
        int tmp;
        cin >> tmp;
        idx_v.push_back(tmp);
    }
    for(int i=0;i<idx_v.size(); i++)
    {
        unordered_map<int,int>::iterator now_it = input_map.find(idx_v[i]);
        if(now_it == input_map.end())
            cout << "0 ";
        else
            cout << now_it->second << " ";
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