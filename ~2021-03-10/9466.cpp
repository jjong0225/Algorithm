#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

typedef struct node
{
    int num;
    struct node* next_ptr;
} Node;


void solution()
{
    // code
    int case_count = 0;
    cin >> case_count;
    for(int now_count = 0; now_count < case_count; now_count++)
    {
        int num;
        cin >> num;
        vector<Node> input_v, vector<int> output;
        for(int i=0; i<=num; i++)
        {
            Node tmp_node = {i, NULL};
            input_v.push_back(tmp_node), output.push_back(0);
        }
        for(int i=1; i<=num; i++)
        {
            int tmp;
            cin >> tmp;
            if(tmp != i)
                input_v[i].next_ptr = &input_v[tmp];
        }
        int team_count = 1;
        for(int i=1; i<=num; i++)
        {
            if(output[i] == 0)
            {
                vector<int> visited_v;
                unordered_set<int> visited_set;
                visited_v.push_back(i), visited_set.insert(i);
                bool is_circuitous = false, is_one = false;
                int first_idx = i;
                while(1)
                {
                    int now_idx = visited_v[visited_v.size()-1];
                    if(input_v[now_idx].next_ptr == NULL)
                        is_one = true, break;
                    int now_num = input_v[now_idx].next_ptr->num;
                    if(output[now_num] != 0)
                        break;
                    else if(visited_set.find(now_num) != visited_set.end())
                    {
                        is_circuitous = true;
                        first_idx = now_num;
                        break;
                    }
                    else
                    {
                        visited_v.push_back(now_num);
                        visited_set.insert(now_num);
                    }
                }

                if(is_circuitous == false)
                {
                    for(int aa=0; aa<visited_v.size()-1; aa++)
                        output[visited_v[aa]] = -1;
                    if(is_one == true)
                    {
                        output[visited_v[visited_v.size()-1]] = team_count;
                        team_count++;
                    }
                    else
                        output[visited_v[visited_v.size()-1]] = -1;
                }
                else
                {
                    bool is_belong = false;
                    for(int aa=0; aa<visited_v.size(); aa++)
                    {
                        if(visited_v[aa] == first_idx || is_belong == true)
                        {
                            output[visited_v[aa]] = team_count;
                            is_belong = true;
                        }
                        else
                            output[visited_v[aa]] = -1;
                    }
                    team_count++;
                }
            }
        }
        int result = 0;
        for(int i=1; i<=num; i++)
        {
            if(output[i] == -1)
                result++;
        }
        cout << result << "\n";
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




// 배울만한 다른사람의 코드
// 난 이미 지나온 node들을 처리하는 방법을 -> vector에 다 넣고 넣고, 들어올 때마다 find함. 그리고 마지막에 한번에 하나의 팀으로 처리함 (누가 팀을 이루는지 다 알수있음)
// 이 사람이 지나온 node들을 처리하는 방법을 ->  배열을 이용하여 넣고, 이미 들어가있는 값을 새로 발견하면 그때 팀이 완성된다고 판단함. 그리고 count만큼 뺌(누구누구가 팀인진 모르지만 몇명인진 앎)

#include<cstdio>
char buf[1<<17];
inline char read(){
	static int idx=1<<17;
	if(idx==1<<17){
		fread(buf, 1, 1<<17, stdin);
		idx=0;
	}
	return buf[idx++];
}
inline int readInt(){
	int sum=0;
	char cur=read();
	while(cur==10 || cur==32)	cur=read();
	while(cur>=48 && cur<=57){
		sum=sum*10+cur-48;
		cur=read();
	}
	return sum;
}
int main(){
	int tc, g[100001], w[100001], N, ans, cnt;
	tc=readInt();
	while(tc--){
		N=readInt();
		for(int i=1;i<=N;++i)	w[i]=readInt(), g[i]=0; // W는 목표 node, g는 연산을 위해 0으로 초기화
		ans=N, cnt=1;
		for(int i=1;i<=N;++i){
			if(g[i])	continue;    //  이미 전에 방문한 node라면 넘기기
			int p=cnt, j=i;
			while(!g[j])	g[j]=cnt++, j=w[j];   // 이미 전에 방문한 노드가 아니라면, g[j]에 몇번째 방문한 노드인지 저장하고, j를 다음노드로 
			if(g[j]>=p)	ans-=cnt-g[j]; // 만약 마지막 노드의 순서가 방문한게 이번에 방문하여 p(이전 count)보다 크다면, 이번에 이동한 만큼 뺀다. (마지막으로 이동된 g[j]가 이미 있는값이라면, cnt-g[j]명이 이루는 팀이 1개가 생성되므로!, 자동적으로 그 외의 인원은 어디에도 속하지 못하게 된다.)
		}
		printf("%d\n", ans);
	}
	return 0;
}