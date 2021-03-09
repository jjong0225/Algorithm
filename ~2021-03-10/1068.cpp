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

typedef struct node
{
    int data;
    vector<node *> children;
}Node;

void solution()
{
    // code
    int n;
    cin >> n;
    Node V[60] = {0};
    int root_idx = 0;
    for(int i=0; i<n; i++)
    {
        int tmp_input = 0;
        cin >> tmp_input;
        V[i].data = i;
        if(tmp_input == -1)
        {
            root_idx = i;
            continue;
        }
        V[tmp_input].children.push_back(&V[i]);
    }
    int delete_idx = 0;
    cin >> delete_idx;
    int output = 0;
    int count = 0;
    queue<int> q;
    q.push(root_idx);
    if(delete_idx == root_idx)
    {
        cout << 0;
        return;
    }
    while(!q.empty())
    {
        int now_idx = q.front();
        q.pop();
        count++;
        int now_count = 0;
        if(V[now_idx].children.size() == 0)
            output++;
        else
        {
            for(int i=0; i<V[now_idx].children.size(); i++)
            {
                if(V[now_idx].children[i]->data != delete_idx)
                {
                    q.push(V[now_idx].children[i]->data);
                    now_count++;
                }
            }
            if(now_count == 0)
                output++;
        }
    }
    if(count == 1)
        output = 1;
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