/*
첫째 줄에는 컴퓨터의 수 (컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다)
둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. (간선 수)
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 바이러스에 걸리게 되는 컴퓨터의 수 (1번 제외해야함)

tree는 ㄴㄴ, 그래프인듯
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

typedef struct node 
{
    int num;
    vector<struct node*> connected_pc;
} Node;

stack<pair<int,int>> E;
int visited[104] = {0};
Node *V[104] = {NULL};
Node V_const[104] = {0};

void travle(Node *now_node)
{
    visited[now_node->num] = 1;
    for(int i=0; i<now_node->connected_pc.size(); i++)
    {
        if(visited[now_node->connected_pc.at(i)->num] == 0)
        {
            travle(&V_const[now_node->connected_pc.at(i)->num]);
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M = 0;
    cin >> N >> M;
    for(int i=1; i<=N; i++)
    {
        V_const[i].num = i;
    }
    for(int i=0; i<M; i++)
    {
        int a,b = 0;
        cin >> a >> b;
        E.push(make_pair(a,b));
    }
    while(!E.empty())
    {
        pair<int,int> now_edge = E.top();
        E.pop();
        int src_idx, dst_idx;
        src_idx = now_edge.first;
        dst_idx = now_edge.second;

        V_const[src_idx].connected_pc.push_back(&V_const[dst_idx]);
        V_const[dst_idx].connected_pc.push_back(&V_const[src_idx]);
        // Node *src = V[src_idx];
        // Node *dst = V[dst_idx];
        // if(src != dst)
        // {
        //     V_const[src_idx]->connected_pc.push_back(V_const[dst_idx]);
        //     V_const[dst_idx]->connected_pc.push_back(V_const[src_idx]);
        //     cout << src_idx << "|||" <<dst_idx << endl;
        //     for(int i=1; i<=N; i++)
        //     {
        //         if(V[i] == V[dst_idx])
        //         {
        //             V[i] = src;
        //         }
        //     }
        // }
    }
    int infected_count=0;
    travle(&V_const[1]);
    for(int i=2; i<=N; i++)
    {
        if(visited[i] == 1)
        {
            infected_count++;
        }
    }
    cout << infected_count;
}

