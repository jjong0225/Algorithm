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
// struct my_compare
// {
//     bool operator()(string &a, string &b)
//     {

//     }
// }


void solution()
{
    // code
    vector<string> str_v;
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n+m; i++)
    {
        string tmp_string;
        cin >> tmp_string;
        str_v.push_back(tmp_string);
    }
    sort(str_v.begin(), str_v.end());
    // vector<string>::iterator it = 
    // unique(str_v.begin(), str_v.end());
    // int x = it - str_v.begin() - 1;
    // int len = str_v.end() - it;
    // cout << len << endl;
    int output =0;
    vector<string> tmp_v;
    for(int x = 0; x<str_v.size()-1; x++)
    {
        if(str_v[x] == str_v[x+1])
        {
            tmp_v.push_back(str_v[x]);
            output ++;
            x++;
        }
    }
    cout << output << endl;
    for(int i=0; i<output; i++)
        cout << tmp_v[i] << endl;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}