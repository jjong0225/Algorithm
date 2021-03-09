#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
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

/*
1 <= N,M <= 2,000 
최솟값을 찾아서 모든 폭발시키기
(2,000 * 2,000, 최솟값 찾기) * (2,000 * 2,000, 모든 폭탄 제거하기)
-> 2*10^3의 4제곱
16 * 10^12
그 다음 것이 영향을 줘야하는데?

최소를 찾아야 할듯

대충 이정도 복잡도
(N-M)*(N-M)*M*M

10^12 -> 개오바

1000, 10^3이라 할 때,

다 구하지 말고, 먼저 다 구간합 모두 구한 후, 구간합끼리의 연산을 통해서 다른 합을 구하는 것!

(방법1)
N개의 수를 배열에 입력받고 i부터 j까지의 합을 입력이 올 때마다 계산해서 반환
시간복잡도: O(n^2) // n*n

(방법2)
Prefix sum을 구해두고 sum(i)(처음부터 i까지의 합) - sum(j-1)(처음부터 j-1까지의 합)을 통해서 반환
시간복잡도: O(n) // n

핵심은 모든것을 0으로 만들어야 함. (위와 왼쪽은 다 됐다고 생각해도 된다, 즉 왼쪽과 위의 최솟값만 봐도 된다. // 반드시 다른 부분이 클거라는 믿음)

2차원의 부분합도 똑같다. 단, 생성하는데 n이 아닌 n^2일 뿐이다 (만약 한번씩 구하면 n^4)
구간합이 중요한가? ㄴㄴ 가장 중요한건 최솟값인데 구간최솟값은 말이안돼
배열 2개로 위치까지?

생각해보니까 굳이 삭제할 필요가 있나?
없지 그냥 output에 넣으면 되니까

*/
int N, M = 0;
vector<vector<int>> input_matr;
vector<vector<int>> output_matr;

int find_min(int cmp_x, int cmp_y)
{
    int min_size = -2147483648;
    for(int explosion_x=M/2*-1; explosion_x<=M/2; explosion_x++)
    {
        for(int explosion_y=M/2*-1; explosion_y<=M/2; explosion_y++)
        {
            if(min_size == 0)
                return 0;
            if(cmp_x+explosion_x<N && cmp_x+explosion_x>=0 && cmp_y+explosion_y >= 0 && cmp_y+explosion_y<N)
                min_size = max(min_size, input_matr[cmp_x+explosion_x][cmp_y+explosion_y]);
        }
    }
    return min_size * -1;
}

void explosion(int cmp_x, int cmp_y)
{
    int bomb_size = find_min(cmp_x, cmp_y);
    if(bomb_size != 0)
    {
        output_matr[cmp_x][cmp_y] += bomb_size;
        for(int explosion_x=M/2*-1; explosion_x<=M/2; explosion_x++)
        {
            for(int explosion_y=M/2*-1; explosion_y<=M/2; explosion_y++)
            {
                if(cmp_x+explosion_x<N && cmp_y+explosion_y<N)
                    input_matr[cmp_x+explosion_x][cmp_y+explosion_y] += bomb_size;
            }
        }
    }
}

void solution()
{
    // code
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        vector<int> tmp_v;
        vector<int> tmp_v_1;
        for(int j=0; j<N; j++)
        {
            int tmp = 0;
            tmp_v_1.push_back(tmp);
            cin >> tmp;
            tmp_v.push_back(tmp);
        }
        input_matr.push_back(tmp_v);
        output_matr.push_back(tmp_v_1);
    }
    int counter = 0;
    for(int shell=M/2; shell<N-M/2 ; shell++)
    {
        for(int y=M/2; y<N-M/2; y++)
        {
            if(input_matr[shell][y] != 0)
                explosion(shell, y);
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << output_matr[i][j] << " ";
        }
        cout << "\n";
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