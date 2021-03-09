
/*


2 * 10^5



10^6 = 1mb
10^3 mb

10^9
dp[]


경로가 cycle을 포함하는가? 왜냐하면 양방향이 존재하므로 -> 2
만나는 cycle의 첫 원소가 그 번호면 안된다.
두 원소가 cycle의 안이다 -> 무조건 2
포함하지 않는가? -> 1

cycle 판별하는게 가장 중요하고 그 cycle 처리가 다음으로 중요

cycle은 어떻게 알고 어떻게 데이터를 처리하지?
tree 구현 후 logN?

근데 문제는 tree
근데 어디가 어떻게 들어갈지는 모르겠어
만약 1 7이 먼저 나온다면 나는 어떤걸 트리로 생각해야하지?

즉 1 7 / 3 7이 같이나온다면?
상관없는거같은데?
cycle이 변하는건 아니니까.


cycle의 번호들
나중에 나오는걸 무조건 무시한다고 생각 (cycle을 만드는 용도만)
그럼 어떻게 travle? 두개의 경로를 둘다 찾는다 

5 -> 7라고 하면

1 -> 5의 경로는
1 -> 2 -> 5

1 -> 7
1 -> 3 -> 7

마지막으로 중복되는 번호 제외 다 무시
마지막 중복 번호를 기준으로 경로탄생
5 -> 2 -> 1 -> 3 -> 7

예시 2
4 -> 5

1 -> 4
1 -> 2 -> 4
1 -> 5
1 -> 2 -> 5

4 -> 2 ->5


이렇게 경로는 완성
그러면 cycle을 포함하자면?
우선 아까 생각햇던 5 -> 7을 보자.
5 -> 2 -> 1 -> 3 -> 7
두 개가 cycle 안에 있다 -> 2
처음 만나는 cycle이 목적지가 아니라면 -> 2
처음 만나는 cycle이 목적지라면 -> 1
cycle이 포함되지 않았다면 -> 1



내 생각은 위와 같았다.
단순 tree 구현 + dfs를 통한 node와 그의 path찾기 + 연산
복잡도 단순 계산
tree 구현 n
dfs : n
q * dfs : n^2 = 4 * 10^10 개오바
연산 : path만큼 대충 생각하면 2 * log n

n + n^2 + 2n*logn

알고리즘 분류를 보면
걍 분리 집합을 이용한 tree구현 + dfs쓰면 될거같긴한데
*분리 집합*이 중요한 키워드였던것 같다.
tree 
tree 구현 : n
dfs : 2*logn
q * dfs : 2n logn



둘다해보자.


*/

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
    int idx;
    vector<node *> connected_ptrv;
} Node;

int N, Q;
vector<Node> tree;
bool checker[200001] = {0};

void solution()
{
    // code
    cin >> N >> Q;
    int cycle_idx_1, cycle_idx_2 = 0;
    for(int i=0; i<=N; i++)
    {
        vector<Node *> init_v;
        Node init_node = {i,init_v};
        tree.push_back(init_node);
    }
    for(int i=0; i<N; i++)
    {
        int tmp_1, tmp_2;
        cin >> tmp_1 >> tmp_2;
        tree[tmp_1].connected_ptrv.push_back(&tree[tmp_2]);
        tree[tmp_2].connected_ptrv.push_back(&tree[tmp_1]);
    }

    for(int count=0; count<Q; count++)
    {
        int tmp_1, tmp_2;
        cin >> tmp_1 >> tmp_2;
        stack<Node *> s;
        s.push(&tree[tmp_1]);
        memset(checker, 0, sizeof(checker));
        checker[tmp_1] = true;
        int output = 0;
        while(!s.empty())
        {
            Node * now_ptr = s.top();
            s.pop();
            if(now_ptr->idx == tmp_2)
            {
                output++;
                continue;
            }
            for(int i=0; i<now_ptr->connected_ptrv.size(); i++)
            {
                Node *tmp_ptr = now_ptr->connected_ptrv[i];
                if(checker[tmp_ptr->idx] == false)
                {
                    s.push(tmp_ptr);
                    checker[tmp_ptr->idx] = true;
                }
            }
        }
        cout << output << endl;
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