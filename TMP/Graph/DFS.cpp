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
    int num;
    struct node* parent;
} Node;

int n;
vector<Node> V;
vector<int> check_v;
int delete_idx = 0;

int dfs(int now_idx)
{
    int output = 0;
    if(V[now_idx].parent != NULL)
    {
        Node *ptr = V[now_idx].parent;
        if(ptr->num == delete_idx)
        {
            check_v[now_idx] = 1;
            return -1;
        }
        else  // check_v[ptr->num] == 0 && 
        {
            output = dfs(ptr->num);
            if(output == -1)
            {
                check_v[now_idx] = 1;
                return -1;
            }
            check_v[ptr->num] = 1;
        }
    }
    return 0;
}

void solution()
{
    // code
    cin >> n;
    for(int i=0; i<n; i++)
    {
        Node tmp_node = {i,NULL};
        V.push_back(tmp_node);
        check_v.push_back(0);
    }
    int root_idx = -1;
    for(int i=0; i<n; i++)
    {
        int input_parent;
        cin >> input_parent;
        if(input_parent == -1)
            root_idx = i;
        else
            V[i].parent = &V[input_parent];
        
    }
    cin >> delete_idx;

    for(int i=0; i<n; i++)
    {
        if(i!=delete_idx)
            dfs(i);
    }
    int output = 0;
    check_v[delete_idx] = 1;
    for(int i=0; i<n; i++)
    {
        if(check_v[i] == 0)
            output++;
    }
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