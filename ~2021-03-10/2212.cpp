#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> input_v;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        input_v.push_back(a);
    }
    sort(input_v.begin(), input_v.end(), less<int>());
    int output = 0;
    vector<int> tmp_v;
    for(int i=0; i<n-1; i++)
        tmp_v.push_back(input_v[i+1]-input_v[i]);
    sort(tmp_v.begin(), tmp_v.end(), greater<int>());
    for(int i=k-1; i<tmp_v.size(); i++)
        output += tmp_v[i];

    cout << output;
}
