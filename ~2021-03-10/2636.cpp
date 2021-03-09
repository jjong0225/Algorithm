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
    // code
    int N,M;
    cin >> N >> M;
    vector<vector<int>> input_map;
    for(int i=0; i<N; i++)
    {
        vector<int> tmp_v;
        for(int j=0; j<M; j++)
        {
            int tmp;
            cin >> tmp;
            tmp_v.push_back(tmp);
        }
        input_map.push_back(tmp_v);
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