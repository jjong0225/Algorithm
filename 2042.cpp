/*     N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 
모든 input은 int형으로도 괜찮다

M은 수의 변경이 일어나는 횟수
K는 구간의 합을 구하는 횟수

결국, 1 + N + M + K 번 입력하고, K번 출력이 나타남

둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다
N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c가 주어진다
이때, a = 1이라면 b번째 수를 c로 바꾸고,
a = 2라면 b번째 수 부터 c번째 수까지의 합을 나타낸다.


입력으로 주어지는 모든 수, OUTPUT = -2^63보다 크거나 같고, 2^63 -1보다 작거나 같다.
long long int여야 한다.

1,000,000 *  8 -> 메모리 걱정 ㄴㄴ
걍 들어올때마다 하면 될거같은데?

시간은?
최대 M번 더한다고 생각해보자
N은 최대일때 처음부터 끝까지 더하는 경우가 M의 최대 번 나온다고 하면
(모든 값의 합 : 10^6) * (연산 횟수 : 10^4) -> 10^10
1억 = 10^8이므로 시간을 오바한다.
더하는 횟수는 어쩔수 없으니(연산을 시도하는 횟수)
더하는 알고리즘의 시간을 줄이는게 관건

세그먼트 트리?로 해결할 수 있다던데 뭔지 모르겠다.
2/n + 4/N + ...

메모리를 이용하는것
다 계산해둔다?
결국에 그러면 하나 바꿀 때마다 연산 해야해서 힘들어

1bit = 10^6MB이므로 X
덧셈을 구할 때 반드시 '연속' 이라는 점이 가장 신경쓰인다

세그먼트 트리 뿐인 듯...

트리 구성과 참조는?
구성은 재귀를 통해서 하면 될거같다.
*/

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct node
{
    long long int partial_sum;
    int start_idx;
    int end_idx;
    struct node *left;
    struct node *right;
};

typedef struct node Node;
long long int input_arr[1000004] = {0};


Node* tree_gen(int a, int b)
{
    Node *new_node_ptr = (Node *)malloc(sizeof(Node));
    if(a == b)
    {
        new_node_ptr->partial_sum = input_arr[a];
        new_node_ptr->left = NULL;
        new_node_ptr->right = NULL;
    }
    else
    {
        int mid = (a+b)/2;
        new_node_ptr -> left = tree_gen(a,mid);
        new_node_ptr -> right = tree_gen(mid+1,b);
        new_node_ptr->partial_sum = new_node_ptr -> left->partial_sum + new_node_ptr -> right->partial_sum;
    }
    new_node_ptr->start_idx = a;
    new_node_ptr->end_idx = b;
    return new_node_ptr;
}

long long int find_sum(int a, int b, Node *parent)
{
    if(parent == NULL)
        return 0;
    if(parent->start_idx > b || parent->end_idx < a)
        return 0;
    else if(parent->start_idx >= a && parent->end_idx <= b)
    {
        return parent->partial_sum;
    }
    else
    {
        return find_sum(a,b,parent->left) + find_sum(a,b,parent->right);
    }
    return 0;    
}

int update_val(int a, long long int val, long long int diff, Node* parent)
{
    if(parent == NULL)
        return 0;
    int parent_a = parent->start_idx;
    int parent_b = parent->end_idx;
    if(parent_a > a || parent_b < a)
        return 0;
    
    if((parent_a == parent_b) && (parent_a == a))
    {
        parent->partial_sum = val;
        return 0;
    }
    else
    {
        parent->partial_sum = parent->partial_sum + diff;
        update_val(a, val, diff, parent->left);
        update_val(a, val, diff, parent->right);
    }
    return 0;;
}

int main ()
{
    int N, M, K = 0;
    cin >> N >> M >> K;
    memset(input_arr,0,sizeof(input_arr));
    for(int i=0; i<N; i++)
    {
        cin >> input_arr[i];
    }
    Node *root = tree_gen(0,N-1);
    for(int i=0; i<M+K; i++)
    {
        int a,b,c = 0;
        cin >> a >> b >> c;
        if(a == 1)
        {
            b--;
            long long int diff = 0;
            diff = c-input_arr[b];
            input_arr[b] = c;
            update_val(b,c,diff,root);
        }
        if (a == 2)
        {
            b--;
            c--;
            cout << find_sum(b,c,root) << endl;
        }
    }
    return 0;
}
