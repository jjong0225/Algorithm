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
    int N = 0;
    cin >> N;
    vector<int> input_v;
    for(int i=0; i<N; i++)
    {
        int tmp  = 0;
        cin >> tmp;
        input_v.push_back(tmp);
    }
    sort(input_v.begin(), input_v.end(), greater<int>());
    int output = input_v[0];
    for(int i=1; i<N; i++)
    {
        if(output < input_v[i]*(i+1))
            output = input_v[i]*(i+1);
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