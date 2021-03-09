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
    string input_str, output_str; // 1000000
    cin >> input_str;
    int now_idx = 0;
    for(int i=0; i<input_str.length(); i++)
    {
        if(now_idx == 0 || input_str[i] != output_str[now_idx-1])
        {
            output_str.push_back(input_str[i]);
            now_idx++;
        }
    }
    cout << output_str.length()/2;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}