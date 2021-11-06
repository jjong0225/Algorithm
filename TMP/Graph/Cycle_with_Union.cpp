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

typedef struct node
{
    int a;
    struct node *parent;
}Node;

Node *get_root(Node *tmp_ptr)
{
    while(tmp_ptr->parent != NULL)
        tmp_ptr = tmp_ptr->parent;
    return tmp_ptr;
}

Node *merge(Node *a_ptr, Node *b_ptr)
{
    Node *new_root = (Node *)malloc(sizeof(Node));
    new_root->parent = NULL;
    a_ptr->parent = new_root;
    b_ptr->parent = new_root;
    return new_root;
}

void solution()
{
    int n, m;
    cin >> n >> m;
    vector<Node> node_v;
    for(int i=0; i<n; i++)
    {
        Node new_node;
        new_node.a = i;
        new_node.parent = NULL;
        node_v.push_back(new_node);
    }

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        Node *a_ptr = get_root(&node_v[a]);
        Node *b_ptr = get_root(&node_v[b]);
        if((a_ptr == b_ptr))
        {
            cout << (i+1);
            return;
        }
        else
        {
            node_v[a].parent = merge(a_ptr, b_ptr);
            node_v[b].parent = node_v[a].parent;
        }


    }
    cout << 0;
    return;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}