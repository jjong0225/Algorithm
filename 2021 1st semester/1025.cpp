#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<list>
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
int input_map[11][11] = {0};

int inversion (int x)
{
    int return_val = 0;
    while(x > 0)
    {
        return_val *= 10;
        return_val += x % 10;
        x = x / 10; 
    }
    return return_val;
}

void solution()
{
    // code
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<m; j++)
        {
            char tmp_c = 0;
            cin >> tmp_c;
            input_map[i][j] = tmp_c - '0';
        }
    } 
    set<int> s;
    for(int i=0; i<=31623; i++) s.insert(i*i);

    int cur_max = -1;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=-1*n; k<=n; k++)
            {
                for(int l= -1*m; l<= m; l++)
                {
                    if((k == 0 && l == 0))
                        continue;
                    int x = 0;
                    int tmp_val = 0;
                    while(1)
                    {
                        if((i + x*k < 0) || (i + x*k >= n) || (j + x*l < 0) || (j + x*l >= m))
                            break;
                        tmp_val = tmp_val*10 + input_map[i + x*k][j + x*l];
                        if(s.find(tmp_val) != s.end())
                            cur_max = max(cur_max, tmp_val);
                        x++;
                    }
                }
            }
        }
    }
    cout << cur_max;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}