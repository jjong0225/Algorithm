/*

dp점화식을 어떻게 새울지에 대해서 이해가 잘 안됐음.
결국엔 키포인트는 문제르 어떻게 소분할 지에 대한 것이 문제였다.
이미 푼, 즉 "위와 왼쪽은 모두 풀렸다고 가정한 후, 현재 점 i,j가 정사각형의 오른쪽 아래 꼭짓점이라고 고정시키면 해결할 수 있었다."
즉, min([i-1][j], [i-1][j-1], [i][j-1]) + 1을 통해 푼것이다.

1번으로는 문제를 어떻게 작은 문제로 나누는지 고려하고 
2번으로는 dp에 저장할 내용을 정의하고
3번으로는 점화식을 새웠어야 했다.

1번 문제를 소분하는 과정에서 prefix sum처럼 접근해서 잘못된 길로 갔던거같다.
이렇게 된 가장 큰 원인이라고 생각하면 고정관념이었던거같다.
이미 푼 하나의 값만을 참고해야 한다고 생각했다.
즉, 3x3는 완성된 2x2에서 오른쪽 변의 3개의 공간을 다 체크하고 아랫 변의 3개의 공간을 다 체크 해야만 된다고 생각했다.
그렇다면 이건 dp가 아니라 for문으로 바뀔것이고 효율적으로 실행되지 않았을 것이다.
하나의 점의 해결을 위해 1개뿐만이 아니라 현재 점 i,j에 대해여 정답에 영향을 끼치는 모든 공간을 확인했어야 했다
dp -> dp가 아닌 문제 <- dp 처럼 dp가 dp를 일으키는게아니라 문제가 dp를 일으키도록 문제에 접근해야 했던것 같다.

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

int N,M = 0;
vector<vector<int>> input_map;

void solution()
{
    // code
    cin >> N >> M;
    int output = 0;
    for(int i=0; i<N; i++)
    {
        vector<int> tmp_v;
        for(int j=0; j<M; j++)
        {
            char tmp_c;
            cin >> tmp_c;
            if(tmp_c == '0')
                tmp_v.push_back(0);
            else
                tmp_v.push_back(1);
            output = max(output, tmp_v.back());
        }
        input_map.push_back(tmp_v);
    }
    for(int i=1; i<N; i++)
    {
        for(int j=1; j<M; j++)
        {
            if(input_map[i][j] == 1)
                input_map[i][j] = min(min(input_map[i][j-1], input_map[i-1][j]), input_map[i-1][j-1]) + 1;
            output = max(output, input_map[i][j]);
        }
    }
    cout << output * output;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}