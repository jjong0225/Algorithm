#include<iostream>
#include<unordered_set>
using namespace std;

int main ()
{
    int counter = 1;
    while(1)
    {
        bool break_flag = 0;
        int edge_count = 0;
        unordered_set<int> nodes;

        while(1)
        {
            int a, b = 0;
            cin >> a >> b;
            if(a == 0 && b == 0)
                break;
            else if (a < 0 && b < 0)
            {
                break_flag = 1;
                break;
            }
            nodes.insert(a);
            nodes.insert(b);
            edge_count++;
        }
        if(break_flag == 1)
            break;

        if(edge_count == 0 || nodes.size() == edge_count + 1)
        {
            cout << "Case " << counter << " is a tree.\n";
        }
        else
        {
            cout << "Case " << counter << " is not a tree.\n";
        }
        counter++;
    }
}