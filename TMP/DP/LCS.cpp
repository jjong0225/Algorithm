#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;


int main() {
	string a;
	string b;
	int dp[1004][1004] ={0};
	cin >> a >> b;
	for(int i=1; i<=a.length(); i++)
	{
		for(int j=1; j<=b.length(); j++)
		{
			if(a.at(i-1) == b.at(j-1))
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}	
	}
	cout << dp[a.length()][b.length()];
	
    return 0;
}
