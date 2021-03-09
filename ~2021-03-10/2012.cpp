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
    int N;
    cin >> N;
    vector<int> input_v;
    input_v.push_back(0);
    for(int i=0; i<N; i++)
    {
        int a;
        cin >> a;
        input_v.push_back(a);
    }
    sort(input_v.begin(), input_v.end(), less<int>());
    long long int output = 0;
    for(int i=1; i<=N; i++)
        output += abs(input_v[i] - i);
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