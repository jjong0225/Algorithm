
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int DP[20002] = {0};
vector<vector<pair<int,int>>> V;

struct my_comparioson
{
    bool operator()(pair<int, int> lhs, pair<int,int> rhs)
    {
        return lhs.second > rhs.second;
    }
};

int main ()
{
    cout << (3<2) ;
}

