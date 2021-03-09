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


bool my_compare(const string &a, const string &b)
{
    if(a.length() != b.length())
        return a.length() < b.length();
    else
    {
        if(a.compare(b) < 0)
            return 1;
        else
            return 0;
    }
}

void solution()
{
    // code
    vector<string> str_v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string tmp;
        cin >> tmp;
        str_v.push_back(tmp);
    }

    sort(str_v.begin(), str_v.end(),my_compare);
    str_v.erase(unique(str_v.begin(),str_v.end()), str_v.end());
    string cmp_str;
    for(int i=0; i<str_v.size(); i++)
    {
        if(i == 0 || cmp_str.compare(str_v[i]) != 0)
        {
            cout << str_v[i] << "\n";
            cmp_str = str_v[i];
        }
    }

}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}