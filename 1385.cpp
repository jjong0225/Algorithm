#include<iostream>
#include<queue>
#include<vector>

using namespace std;
vector<vector<int>> E;

int main ()
{
    int a,b,d = 0;
    int n = 1;
    cin >> a >> b;
    if(b > a)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    for(int i=1; i<1000; i++)
    {
        if(3*i*(i+1)+1 >= a)
        {
            d = i; // 1은 깊이가 0이고, 
            break;
        }
    }
    for(int i=0; i<=d; i++)
    {
        vector<int>a;
    }

    a--;
}