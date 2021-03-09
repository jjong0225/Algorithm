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

vector<int> input_v;
vector<int> dis_v;
int N,C;

bool param_serach(int num)
{
    int now_sum = 0;
    int counter = 0;
    for(int i=0; i<dis_v.size(); i++)
    {
        now_sum += dis_v[i];
        if(now_sum >= num)
        {
            counter++;
            now_sum=0;
        }
    }
    if(counter >= C-1)
        return true;
    else
        return false;
}


void solution()
{
    // code
    cin >> N >> C;
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        input_v.push_back(tmp);
    }
    sort(input_v.begin(), input_v.end(), less<int>());
    int low = 1000000001;
    int high = input_v[N-1] - input_v[0];
    for(int i=0;i<N-1;i++)
    {
        int tmp = input_v[i+1]-input_v[i];
        low = min(low, tmp);
        dis_v.push_back(tmp);
    }

    int output = -1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if (param_serach(mid))
        {
            output = max(output, mid);
            low = mid+1;
        }
        else
            high = mid-1;
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