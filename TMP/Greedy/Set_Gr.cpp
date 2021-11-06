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

const int MY_INT_MAX = 2000000000;

void solution()
{
    // code
    int n,k, output=0; // n 과 k는 100보다 작거나 같다.
    cin >> n >> k;
    vector<int> input_v;
    set<int> now_s;
    int init_count = 0;
    for(int i=0; i<k; i++)
    {
        int tmp_d = 0;
        cin >> tmp_d;
        input_v.push_back(tmp_d);
        if(init_count < n)
        {
            if(now_s.find(tmp_d) == now_s.end())
            {
                now_s.insert(tmp_d);
                init_count++;
            }
        }
    }

    for(int i=n; i<k; i++)
    {
        if(now_s.find(input_v[i]) == now_s.end())
        {
            output++;
            set<int> tmp_s = now_s; 
            int tmp_count = 0;
            for(int j=i+1; j<k; j++)
            {
                if(tmp_s.find(input_v[j]) != tmp_s.end()) // 아직 있다면
                {
                    tmp_count++;
                    tmp_s.erase(input_v[j]);
                    if(tmp_count == n)
                    {
                        now_s.erase(input_v[j]);
                        now_s.insert(input_v[i]);
                        break;
                    }
                }
            }
            if(tmp_count != n)
            {
                now_s.erase(*tmp_s.begin());
                now_s.insert(input_v[i]);
            }
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