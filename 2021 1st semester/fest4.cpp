#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<list>
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

double pref_v[5];

struct my_cmp
{
    bool operator()(array<int,4>lp, array<int,4> rp )
    {
        if(lp[0] != rp[0])
            return lp[0] > rp[0];
        else if(pref_v[lp[1]] != pref_v[rp[1]])
            return pref_v[lp[1]] > pref_v[rp[1]];
        else if(lp[2] != rp[2])
            return lp[2] < rp[2];
        else
            return lp[3] < rp[3];
    }
};

void solution()
{
    // code
    for(int i=0; i<5; i++)
        cin >> pref_v[i];

    int n,m;
    cin >> n >> m;

    vector<vector<int>> movie_stat;
    for(int i=0; i<n; i++)
    {
        vector<int> tmp_v;
        for(int j=0; j<m; j++)
        {
            char tmp_c;
            cin >> tmp_c;
            if(tmp_c == 'W')
                tmp_v.push_back(0);
            else if(tmp_c == 'O')
                tmp_v.push_back(1);
            else if(tmp_c == 'Y')
                tmp_v.push_back(2);
        }
        movie_stat.push_back(tmp_v);
    }

    vector<vector<int>> movie_genre;
    for(int i=0; i<n; i++)
    {
        vector<int> tmp_v;
        for(int j=0; j<m; j++)
        {
            char tmp_c;
            cin >> tmp_c;
            tmp_v.push_back(tmp_c-'A');
        }
        movie_genre.push_back(tmp_v);
    }

    vector<array<int,4>> arr_v;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(movie_stat[i][j] != 0)
            {
                array<int,4> insert_el = {movie_stat[i][j], movie_genre[i][j], i, j};
                arr_v.push_back(insert_el);
            }
        }
    }
    sort(arr_v.begin(), arr_v.end(), my_cmp());
    for(int i=0; i<arr_v.size(); i++)
        printf("%c %.1lf %d %d\n", (arr_v[i][1] + 'A'), pref_v[arr_v[i][1]], arr_v[i][2], arr_v[i][3]);
}

int main ()
{
    // iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}