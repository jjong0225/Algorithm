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

typedef struct node {
    char num;
    struct node *lc;
    struct node *rc;
} Node;

vector<Node> V;

void dfs()
{
    stack<Node *>q;
    q.push(&V[0]);
    while(!q.empty())
    {
        Node *now_node = q.top();
        cout << now_node->num;
        q.pop();
        if(now_node->rc != NULL)
            q.push(now_node->rc);
        if(now_node->lc != NULL)
            q.push(now_node->lc);
    }
}

void dfs_1(Node *now_node)
{
    if(now_node->lc != NULL)
        dfs_1(now_node->lc);
    cout << now_node->num;
    if(now_node->rc != NULL)
        dfs_1(now_node->rc);
}

void dfs_2(Node *now_node)
{
    if(now_node->lc != NULL)
        dfs_2(now_node->lc);
    if(now_node->rc != NULL)
        dfs_2(now_node->rc);
    cout << now_node->num;
}

void solution()
{
    // code
    int n;
    cin >> n;
    for(char i=0; i<n; i++)
    {
        Node init_Node = {(char)(i+'A'), NULL, NULL};
        V.push_back(init_Node);
    }
    for(int i=0; i<n; i++)
    {
        char a,b,c;
        cin >> a >> b >> c;
        if(b != '.')
           V[a-'A'].lc = &V[b-'A'];
        if(c != '.')
           V[a-'A'].rc = &V[c-'A'];
    }
    dfs();
    cout << endl;
    dfs_1(&V[0]);
    cout << endl;
    dfs_2(&V[0]);
    cout << endl;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}