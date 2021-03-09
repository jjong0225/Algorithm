/*

N개의 눈덩이 | N (4 ≤ N ≤ 600)
각 눈덩이의 지름 H_i |  i (1 ≤ i ≤ N), H_i (1 ≤ Hi ≤ 10^9)
하나의 눈사람 = 두개의 눈덩이 (머리 몸통)
H_머리 <= H_몸통 (크지 않다 -> 작거나 같다)
키 = H_머리 + H_몸통


N개 중 4개 골라 눈사람 2개 만들기
두 눈사람의 키 차이가 최솟값이 되도록 만들고, 이 최솟값을 구해라

두개를 찾는다

머리와 몸통의 크기 조건은 생각하지 않아도 된다 (그냥 뽑기만 해도 자동으로 큰 쪽이 몸통이 되기 때문에)
따라서, 2개 눈덩이 합의 키 간의 차이를 두면 된다.
[600][600] -> 크기 자체는 괜찮다

최소 차이를 찾는다
눈사람 경우의 수 : 600 + 599 + 588 ... + 1 = 601 * 300 = 180300
눈사람 비교 경우의 수 : 180300^2 -> 개오바 
그럼 눈사람을 만들고, 크기별로 sorting 한다. (우선순위 힙 ㄴㄴ, qsortㄱㄱ)
이후에 확인하는 idx +- 1의 원소들을 확인해가면서 min_diff을 갱신해간다
만약 비교 중, 같은 눈덩이가 두번 나온다면?
다른게 나올 때 까지 찾는다?
최악의 경우라면?
a,b,a+b
ㄴㄴ 같은 크기의 눈사람이 나올 가능성이 있다.

크기별로 sorting한다음에 걍 4개 배열로 다 비교하기?
4~600
600^4 = 1200  * 10^2^4 = 1.2 * 10^11 ㄴㄴ
or 180300^2 = 10^10 ㄴㄴ

가장 문제는 같은 눈덩이를 사용하는 경우를 제외해야한다

2 3 5 5 9

0
1
2
3
4
6
7

2개 더하고
2개 더하고
뺀 것의 절대값

2 3 5 5 9
2 3 5 5 -> 1
2 3 5 9 -> 3
2 3 5 9 -> 3
2 5 5 9 -> 1
3 5 5 9 -> 2
*/

#include<iostream>
#include<map>
#include<cstring>
#include <algorithm>

using namespace std;

int my_compare(const void *a, const void *b)
{
    if(*((int *)a) > *((int *)b)) return 1;
    if(*((int *)a) < *((int *)b)) return -1;
    if(*((int *)a) == *((int *)b)) return 0;
    return 0;
}

int N[600] = {0};
int main ()
{
    int n=0;
    cin >> n;
    int output = 1000000002;
    for(int i=0; i<n; i++)
    {
        cin >> N[i];
    }
    qsort(N,n,sizeof(N[0]),my_compare);
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n;j++)
        {
            int comp_size = N[i] + N[j];
            int a=i+1;
            int b=n-1;
            while(1)
            {
                if(a == i || a == j)
                    a++;
                if(b == i || b == j)
                    b--;
                if(a >= b)
                    break;

                if(comp_size > N[a]+N[b])
                {
                    output = min(output, comp_size-(N[a]+N[b]));
                    a++;
                }
                else if(comp_size < N[a]+N[b])
                {
                    output = min(output, (N[a]+N[b])-comp_size);
                    b--;
                }
                else if (comp_size == N[a]+N[b])
                {
                    cout << '0';
                    return 0;
                }
            }
        }
    }
    cout << output;
    return 0;
}