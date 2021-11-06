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

struct my_cmp 
{
    bool operator()(array<int,3>lp, array<int,3>rp)
    {
        return lp[2] > rp[2];
    }
};

typedef struct node_struct
{
    struct node_struct *parent;
    int val;
}Node;

Node * get_root(Node *param_node)
{
    while(param_node->parent != NULL)
    {
        param_node = param_node->parent;
    }
    return param_node;
}

int merge_tree(Node *left, Node *right)
{
    Node *lr = get_root(left);
    Node *rr = get_root(right);

    if(lr != rr)
    {
        Node *new_root = (Node *)malloc(sizeof(Node));
        new_root->parent = NULL;
        lr->parent = new_root;
        rr->parent = new_root;
        return 1;
    }
    else
        return 0;
}


void solution()
{
    // code
    int n, m;
    cin >> n >> m;
    priority_queue<array<int,3>, vector<array<int,3>> ,my_cmp> pq;
    for(int i=0; i<m; i++)
    {
        array<int,3> a;
        cin >> a[0] >> a[1] >> a[2];
        pq.push(a);        
    }
    vector<Node> dp;
    for(int i=0; i<=n; i++)
    {
        Node a;
        a.val = i;
        a.parent = NULL;
        dp.push_back(a);
    }
    lld output = 0;
    while(!pq.empty())
    {
        array<int,3> top_arr = pq.top();
        pq.pop();
        if(merge_tree(&dp[top_arr[0]], &dp[top_arr[1]]))
            output += top_arr[2];
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