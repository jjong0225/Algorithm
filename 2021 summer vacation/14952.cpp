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

int first_col = 0;
int input_map[4][4] = {0};
int last_place[4] = {0};

int is_gameover(int last_row, int last_col, int turn)
{
    if(last_row >= 2) // 세로
    {
        int i=last_row;
        for(; i > last_row-3; i--)
        {
            if(input_map[i][last_col] != turn)
                break;
        }
        if(i == last_row-3)
            return 1;
    }
    // 가로
    if(last_col <= 2)
    {
        int i=0;
        for(; i<3; i++)
        {
            if(input_map[last_row][i] != turn)
                break;
        }
        if(i == 3)
            return 1;
    }

    // if(last_row >= 2 && last_col >= 2)
    // {
    //     int i=0;
    //     for(; i<3; i++)
    //     {
    //         if(input_map[last_row-i][last_col-i] != turn)
    //             break;
    //     }
    //     if(i == 3)
    //         return 1;
    // }
    return 0;
}

int dfs(int a, int b, int turn)
{
    if(b == 0 && a-1 == first_col)
        return 1;
    int output = 0;
    input_map[a][b] = turn;
    if(!is_gameover(a,b,turn))
    {
        for(int i=0; i<4; i++)
        {
            if(last_place[i] == 0)
            {
                for(int j=0; j<4; j++)
                {
                    last_place[i] = j;
                    output += dfs(i,last_place[i],(turn%2)+ 1);
                    last_place[i] = 0;
                }
            }
            else 
            {
                last_place[i]-=1;
                output += dfs(i,last_place[i],(turn%2)+ 1);
                last_place[i]+=1;
            }
        }
    }
    input_map[a][b] = 0;
    return output;
}

void solution()
{
    cin >> first_col;
    int a,b;
    cin >> a >> b;

    a--;
    b--;
    last_place[b] = a;
    int output = dfs(a,b,1);
    output += dfs(a,b,2);
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