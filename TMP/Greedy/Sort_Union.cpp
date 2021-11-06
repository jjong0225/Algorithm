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

typedef struct tmp 
{
    int num;
    struct tmp *parent;
}Node;

Node *find_root_ptr(Node * now_node)
{
    Node* tmp_node = now_node;
    while(tmp_node->parent != NULL)
        tmp_node = tmp_node -> parent;
    return tmp_node;
}

Node *connect_two_tree(Node * t_1, Node * t_2)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *r_1 = find_root_ptr(t_1), *r_2 = find_root_ptr(t_2);
    if(r_1->num > r_2->num)
    {
        Node *sift_n = r_2;
        r_2 = r_1;
        r_1 = sift_n;
    }
    r_2->parent = r_1;
    return new_node;
}

int node_set[100001] = {0};


int find_in_set(int ld)
{
    if(node_set[ld] == ld)
        return ld;
    return node_set[ld] = find_in_set(node_set[ld]);
}


void union_set(int ld, int rd)
{
    int u = find_in_set(ld);
    int v = find_in_set(rd);
    node_set[u] = v;
}

void solution()
{
    int G,P;
    cin >> G >> P;
    // vector<Node> node_set;
    // for(int i=0; i<=G; i++)
    //     node_set.push_back({i,NULL});
    for(int i=0; i<=G; i++)
        node_set[i] = i;
    int output = 0;
    for(int i=0; i<P; i++)
    {
        int tmp;
        cin >> tmp;
        int x = find_in_set(tmp);
        if(x == 0)
            break;
        else
            union_set(x, x-1);
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