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
#include<list>

#include<algorithm>
#include<math.h>
#include<climits> // 자료형 limit포함


using namespace std;

typedef long long int lld;
int parent[100002];

int my_find(int x){
  if (parent[x] < 0){
    return x;
  }
  else{
    int y = my_find(parent[x]);
    parent[x] = y;
    return y;
  }
}

bool my_union(int x, int y){
  x = my_find(x);
  y = my_find(y);
  
  if (x == y)
    return false;
  
  // parent[x], parent[y] 값은 음수이므로 값이 작은 경우가 더 높이가 큰 노드이다.
  if (parent[x] < parent[y]){
    parent[x] += parent[y];
    parent[y] = x;
  }
  else {
    parent[y] += parent[x];
    parent[x] = y;
  }
  return true;
}

struct my_cmp {
    bool operator()(array<lld,3> lp, array<lld,3> rp)
    {
        return lp[2] < rp[2] ;
    }
};

int main ()
{
    int n,m;
    cin >> n >> m;
    for (int i=0; i<=m; i++)
        parent[i] = -1;
    priority_queue<array<lld,3>, vector<array<lld,3>>, my_cmp> pq;
    for (int i=0; i<m; i++)
    {
        array<lld,3> tmp_arr;
        cin >> tmp_arr[0] >> tmp_arr[1] >> tmp_arr[2];
        pq.push(tmp_arr);
    }
    int str, dest;
    cin >> str >> dest;
    lld output = 1000000100;
    while(!pq.empty())
    {
        array<lld,3> tmp_arr = pq.top();
        pq.pop();
        if(my_union(tmp_arr[0], tmp_arr[1]))
        {
            output = min(output, tmp_arr[2]);
            if(parent[str] != -1 && parent[dest] != -1 && (my_find(str) == my_find(dest)))
                break;
        }
    }
    cout << output;
    return 0;
}