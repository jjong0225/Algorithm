/*
1 ≤ K < N ≤ 500,000 = 5*10^5
N개의 string에서 K개를 지워서 가장 큰 수를 만든다.

예제 입력1
4 2
1924 

예제 출력1
94

가장 큰 수?
결국엔 K에서 K-N길이 중 가장 큰 수를 찾는 문제.

가장 큰 수의 조건 : 위에서 부터 가장 커야한다.
OR 연속된 큰 수?
9를 모두 선택하고
8을 그 다음에 선택하고
7을 그 다음에
.....
한번 돌아서 모든 숫자의 크기를 다 구한다.
ㄴㄴㄴ
위치도 중요하지 않나?

예를들어 9891 이렇게
8을 넣을 생각보단 9를 우선으로 넣을 생각을 먼저 했으므로!
991 > 989
or 최대에 대해서 다 구해놔

NlogN안에 풀어야 하는 문제야

1890 2개
90이 최대
현재 자리를 k라고 할 때, 그렇다면 이친구가 봐야할 위치는 1~(4-2+1) = 1~3
확인했을 때 9가 최대였어. 그러면 그 자리를 넘기고 다음걸로 연결해나아가면 된다.
들어갔다가 다시 돌아오는 경우도 있다.
가장 문제인게 이거임. 만약 돌아갔다면 그만큼 데이터를 줘야하니까
안돌아간다면?
k까지의 최대와 최소를 메모리로 저장가능하지만, 영역때문에 개오바임
priority_queue에서 계속 넣는거야. 굿굿.
ㅈㅁ 근데 이렇게하면 데이터가 섞여.
예를들어 8912 이렇게 있고 2개를 선택하려고 891을 읽어서 9를 가져와. 근데 1이 되어야 하는데
특성때문에 8이 나오니까.

그 자리부터 시작하게 하는게 포인트이다.
최대의 값과 위치를 준 다음 거기서 부터 중복되는 부분이 문제인데
이 중복을 사라지게 하는방법?

8912
erase안됌
-1으로 바꾼다면?
-1 -1 1 2
50만개에서 25만개 고른다고 해보자.
25만개 보고 만약에 맨 첨이 단점이라면
25만*25만
 = 2 * 10^5 ㄴㄴ
앞을 뺀는게 좋은가 뒤를 빼는게 큰가? ㄴㄴㄴ 중간에 큰 값이 있을 수 있어
1924
924
어떤 수를 없애는게 가장 좋은가?
1~x에서 가장 작은 수!
1~3에서 가장 작은 수는?

9891
3개이니까
98 중 9선택
89 중 8 선택 여기서 끝
1 선택 (자동, 100프로 최대임)
최대를 선택하고
queue를 통해 구현하자.
최대를 발견할 때 까지 큐에 넣고 그 수가 나올 때 까지 ㅇㅇㅇㅇ
이 수의 관리는 배열로써 갯수 새자.
0~n-k까지
*/

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<math.h>

using namespace std;

int main ()
{
    int n,k;
    string a;
    cin >> n >> k;
    cin >> a;
    int digit_count[10] = {0};
    int now_digit = k;
    queue<int> q;
    for(int i=0; i<now_digit; i++)
    {
        q.push(a[i]-'0');
        digit_count[a[i]-'0']++;
    }

    string output_str;
    for(int i=now_digit; i<a.length(); i++)
    {
        q.push(a[i]-'0');
        digit_count[a[i]-'0']++;
        int next_digit = -1;
        for(int j=0; j<=9; j++)
        {
            if(digit_count[j] != 0)
                next_digit = max(next_digit, j);
        }
        output_str.push_back(next_digit + '0');
        while(!q.empty())
        {
            int tmp_digit = q.front();
            q.pop();
            digit_count[tmp_digit]--;
            if(tmp_digit == next_digit)
                break;
        }
    }
    cout << output_str;
}
