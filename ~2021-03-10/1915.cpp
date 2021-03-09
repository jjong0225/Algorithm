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

int N,M = 0;
vector<vector<int>> input_map;

void solution()
{
    // code
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        vector<int> tmp_v;
        for(int j=0; j<M; j++)
        {
            char tmp_c;
            cin >> tmp_c;
            if(tmp_c == '0')
                tmp_v.push_back(0);
            else
            {
                if(j == 0)
                    tmp_v.push_back(1);
                else
                {
                    tmp_v.push_back(tmp_v[j-1] + 1);
                }
            }
        }
        input_map.push_back(tmp_v);
    }

    int output = 0;
    for(int now_col = M-1; now_col >=0; now_col--)
    {
        int from_the_bottom[1001] = {0};
        int from_the_top[1001] = {0};
        for(int now_row = 0; now_row < N; now_row++)
        {
            if(now_row == 0)
            {
                if (input_map[now_row][now_col] != 0)
                    from_the_bottom[now_row] = 1;
            }
            else
            {
                if(input_map[now_row][now_col] == 0)
                    from_the_bottom[now_row] = 0;
                else if (input_map[now_row-1][now_col] < input_map[now_row][now_col])
                    from_the_bottom[now_row] = 1;
                else if(input_map[now_row-1][now_col] >= input_map[now_row][now_col])
                    from_the_bottom[now_row] = from_the_bottom[now_row-1] + 1;
            }
        }

        for(int now_row = N-1; now_row >= 0; now_row--)
        {
            if(now_row == N-1)
            {
                if (input_map[now_row][now_col] != 0)
                    from_the_top[now_row] = 1;
            }
            else
            {
                if(input_map[now_row][now_col] == 0)
                    from_the_top[now_row] = 0;
                else if (input_map[now_row+1][now_col] < input_map[now_row][now_col])
                    from_the_top[now_row] = 1;
                else if(input_map[now_row+1][now_col] >= input_map[now_row][now_col])
                    from_the_top[now_row] = from_the_top[now_row+1] + 1;
            }
        }

        for(int now_row = 0; now_row < N; now_row++)
        {
            from_the_bottom[now_row] += from_the_top[now_row]-1;
            output = max(output, min(from_the_bottom[now_row], input_map[now_row][now_col]));
            cout << from_the_bottom[now_row] << " ";
        }
        cout << endl;
    }
    cout << output*output;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}