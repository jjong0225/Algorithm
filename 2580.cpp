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
int input_map[11][11] = {0};

vector<pair<int,int>> blank_v;


void dfs(int idx)
{
    if(idx == blank_v.size())
    {
        int check_arr[10] = {0};
        for(int i=1; i<=9; i++)
        {
            for(int j=1; j<=9; j++)
            {
                check_arr[input_map[i][j]]++;
                }
        }
        for(int i=1; i<=9; i++)
        {
            if(check_arr[i] != 9)
                return;
        }
        for(int i=1; i<=9; i++)
        {
            for(int j=1; j<=9; j++)
            {
                cout << input_map[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    }

    int r = blank_v[idx].first;
    int c = blank_v[idx].second;

    int check_arr[10] = {0};
    for(int i=1; i<=9; i++)
    {
        check_arr[input_map[r][i]] = 1;
        check_arr[input_map[i][c]] = 1;
    }

    int r_idx = r - (r-1)%3;
    int c_idx = c - (c-1)%3;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            check_arr[input_map[r_idx + i][c_idx + j]] = 1;
        }
    }
    for(int i=1; i<=9; i++)
    {
        if(check_arr[i] == 0)
        {
            input_map[r][c] = i;
            dfs(idx+1);
            input_map[r][c] = 0;
        }
    }
}

void solution()
{
    // code
    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=9; j++)
        {
            cin >> input_map[i][j];
            if(input_map[i][j] == 0)
                blank_v.push_back(make_pair(i,j));
        }
    }
    if(blank_v.size() != 0)
        dfs(0);

}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}