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

vector<vector<bool>> input_map;
vector<vector<int>> check_map;
int n;

void travle(int row, int col, int num)
{
    input_map[row][col] = 0;
    check_map[row][col] = num;
    if(row+1 < n && input_map[row+1][col]==1)
        travle(row+1, col, num);
    if(row-1 >= 0 && input_map[row-1][col]==1)
        travle(row-1, col, num);
    if(col+1 < n && input_map[row][col+1]==1)
        travle(row, col+1, num);
    if(col-1 >= 0 && input_map[row][col-1]==1)
        travle(row, col-1, num);
}

void solution()
{
    // code

    cin >> n;
    for(int i=0; i<n; i++)
    {
        vector<int> tmp_v;
        vector<bool> tmp_c;
        for(int j=0; j<n; j++)
        {
            char a;
            cin >> a;
            tmp_v.push_back(0);
            if(a == '0')
               tmp_c.push_back(0);
            else
               tmp_c.push_back(1);
        }
        input_map.push_back(tmp_c);
        check_map.push_back(tmp_v);
    }
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(input_map[i][j] == true)
            {
                count++;
                travle(i,j,count);
            }
        }
    }
    vector<int> num_of_set;
    for(int i=0; i<=count; i++)
        num_of_set.push_back(0);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(check_map[i][j] != 0)
                num_of_set[check_map[i][j]]++;
        }
    }
    sort(num_of_set.begin(), num_of_set.end(), less<int>());
    cout << count << endl;
    for(int i=1; i<=count; i++)
        cout << num_of_set[i] << endl;

}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}