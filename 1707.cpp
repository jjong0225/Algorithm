#include<iostream>
#include<vector>

using namespace std;

int dfs(int v_number, int flag, vector<vector<int>> *input_e, vector<int> *check_v)
{
    int return_val = 0;
    for(int i=0; i<(*input_e)[v_number].size(); i++)
    {
        int next_v = (*input_e)[v_number][i];
        if((*check_v)[next_v] == 0)
        {
            (*check_v)[next_v] = (flag%2) + 1;
            return_val = dfs(next_v, (flag%2) + 1, input_e, check_v);
            if(return_val == -1)
                return -1;
        }
        else if((*check_v)[next_v] == flag)
        {
            return -1;
        }
    }
    return 0;
}

int main ()
{
    int count;
    cin >> count;
    for(int now_counter=0; now_counter<count; now_counter++)
    {
        //정점의 개수 V(1≤V≤20,000 : 10^4)와 간선의 개수 E(1≤E≤200,000)가
        int v,e;
        cin >> v >> e;
        vector<vector<int>> input_e;
        vector<int> check_v;
        vector<int> init_v;

        for(int i=0; i<=v; i++)
        {
            init_v.push_back(0);
            check_v.push_back(0);
            vector<int> tmp_v;
            input_e.push_back(tmp_v);
        }
        
        for(int i=0; i<e; i++)
        {
            int a,b;
            cin >> a >> b;
            input_e[a].push_back(b);
            input_e[b].push_back(a);
        }
        int output = 0;
        for(int i=1; i<=v; i++)
        {
            if(check_v[i] == 0 && input_e[i].size() != 0)
            {
                vector<int> param_v = init_v;
                param_v[i] = 1;
                output = min(output, dfs(i, 1, &input_e, &param_v));
                if(output == -1)
                    break;
                for(int k=1; k<=v; k++)
                {
                    if(check_v[k] == 0 && param_v[k] != 0)
                    {
                        check_v[k] = param_v[k];
                    }
                }
            }
        }
        for(int k=1; k<=v; k++)
        {
            if(check_v[k] == 0)
            {
                output = -1;
                break;
            }
        }
        if(output == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}