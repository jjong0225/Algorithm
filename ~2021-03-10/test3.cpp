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


using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> my_set[21];
    for(int i=0; i<phone_book.size(); i++)
    {
        for(int j=0; j<phone_book[i].length()-1; j++)
        {
            string new_str = phone_book[i].substr(0,j+1);
            my_set[j+1].insert(new_str);
        }
    }
    for(int i=0; i<phone_book.size(); i++)
    {
        if (my_set[phone_book[i].length()].find(phone_book[i]) == my_set[phone_book[i].length()].end())
        {
            return false;
        }
    }
    return answer;
}

void solution()
{
    // code
    // 동적으로 활용할 수 있는 배열
    int checker[10] = {0};
    vector<int> adj[10];
    int v, e;
    cin >> v >> e;
    int first_idx = -1;
    for(int i=0; i< e;i++){
        int u, v;
        cin >> u >> v;
        if(first_idx == -1)
            first_idx = u;
        adj[u].push_back(v);
    }
    stack<pair<int,int>> s;
    s.push(make_pair(first_idx,0));
    checker[first_idx] = 1;
    int count = 0;
    while(!s.empty())
    {
        pair<int,int> now_idx = s.top();
        s.pop();
        cout << "v num : " << now_idx.first << " | counter " << now_idx.second << " : ";
        for(int i=0; i<adj[now_idx.first].size(); i++)
        {
            int dst_idx = adj[now_idx.first][i];
            if(checker[dst_idx] == 0)
            {
                s.push(make_pair(dst_idx, now_idx.second+1));
                cout <<dst_idx << ' ';
                checker[dst_idx] = 1;
            }
        }
        count++;
        cout << endl;
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