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

/*
1 <= n,m <=1,000(10^3)
*/
vector<vector<bool>> input_map;
vector<vector<int>> DP[2];
int N, M;
int max_int = 1000000000;

void travle(int row, int col, int num, bool flag)
{
    cout << col << " " << row << " " << num << endl;
    if(DP[flag][row][col] == max_int)
        DP[flag][row][col] = num;
    else
    {
        if(DP[flag][row][col] <= num)
            return;
    }

    if(row+1 < N)
    {
        if(input_map[row+1][col]==1 && DP[flag][row+1][col] < num+1)
            travle(row+1,col,num+1,flag);
        else if(input_map[row+1][col]==0 && flag == 0 && DP[1][row+1][col] < num+1)
            travle(row+1,col,num+1,1);
    }
    if(row-1 >= 0)
    {
        if(input_map[row-1][col]==1 && DP[flag][row-1][col] < num+1)
            travle(row-1, col, num+1, flag);
        else if(input_map[row-1][col]==0 && flag == 0 && DP[1][row-1][col] < num+1)
            travle(row-1, col, num+1, 1);
    }
    if(col+1 < N)
    {
        if(input_map[row][col+1]==1 && DP[flag][row][col+1] < num+1)
            travle(row, col+1, num+1, flag);
        else if(input_map[row][col+1] == 0 && flag == 0 && DP[1][row][col+1] < num+1)
            travle(row, col+1, num+1, 1);
    }
    if(col-1 >= 0)
    {
        if(input_map[row][col-1]==1 && DP[flag][row][col-1] < num+1)
            travle(row, col-1, num+1, flag);
        else if(input_map[row][col-1]==0 && flag == 0 && DP[1][row][col-1] < num+1)
            travle(row, col-1, num+1, 1);
    }
}
void solution()
{
    // code
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        vector<bool> tmp_v;
        vector<int> tmp_dp;
        for(int j=0; j<M; j++)
        {
            char a;
            cin >> a;
            if(a == '1')
                tmp_v.push_back(false);
            else if(a == '0')
                tmp_v.push_back(true);
            tmp_dp.push_back(max_int);
        }
        input_map.push_back(tmp_v);
        DP[0].push_back(tmp_dp);
        DP[1].push_back(tmp_dp);
    }
    travle(0,0,0,0);
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}