#include<iostream>
#include<vector>
#include<queue>
using namespace std;


typedef struct tmp_struct
{
	int departure;
	int destination;
	int weight;
}vertice;

vector< vector<vertice> > E;	
int V_NUM;
int E_NUM;
int DP[110][110] = {0};

struct ver_comp
{
	bool operator()(vertice a, vertice b)
	{
		return a.weight > b.weight;
	}
};

int main ()
{
	cin >> V_NUM >> E_NUM;
	for(int i=0; i<= V_NUM; i++)
	{
		vector<vertice> tmp_vec;
		E.push_back(tmp_vec);
	}
	for(int i=1; i<= E_NUM; i++)
	{
		vertice tmp_ver;
		int start, end, val;
		cin >> start >> end >> val;
		tmp_ver.departure = end;
		tmp_ver.destination = end;
		tmp_ver.weight = val;
		E.at(start).push_back(tmp_ver);
	}
	
	

	for(int i=1; i<= V_NUM; i++)
	{
		priority_queue<vertice, vector<vertice>, ver_comp > weight_pq;
		int visited[110][110] = {0};
		for(int k=0; k<E.at(i).size(); k++ )
		{
			weight_pq.push(E.at(i).at(k));
		}
		while(!weight_pq.empty())
		{
			vertice now_ver = weight_pq.top();
			weight_pq.pop();
			if(visited[i][now_ver.destination] == 1)
				continue;
			visited[i][now_ver.destination] = 1;
			visited[now_ver.departure][now_ver.destination] = 1;
			DP[i][now_ver.destination] = now_ver.weight;
			for(int k=0; k<E.at(now_ver.departure).size(); k++ )
			{
				vertice push_ver = E.at(now_ver.departure).at(k);
				if(visited[i][push_ver.destination] == 1)
					continue;
				push_ver.weight = push_ver.weight + now_ver.weight;
				weight_pq.push(push_ver);
			}
		}
	}
	
	
	
	for(int i=1; i<= V_NUM; i++)
	{
		DP[i][i] = 0;
	}
	for(int i=1; i<= V_NUM; i++)
	{
		for(int j=1; j<= V_NUM; j++)
		{
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}
}