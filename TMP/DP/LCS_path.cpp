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
	cout << dp[a.length()][b.length()] << endl;
	int i=a.length();
	int j=b.length();
	char output_string[1004] = {0};
	int now_pos = dp[a.length()][b.length()] - 1;
	while(1)
	{
		if((dp[i][j] == dp[i-1][j-1] + 1) && (a.at(i-1) == b.at(j-1)))
		{
			output_string[now_pos] =  a.at(i-1);
			now_pos--;
			i--;
			j--;
		}
		else if (dp[i-1][j] > dp[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
		
		if(i == 0 || j == 0 || now_pos < 0)
			break;
	}
	cout << output_string;

	return 0;
}
