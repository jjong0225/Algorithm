#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<string.h>
#include <stdlib.h>

using namespace std;

int input[25] = {0};
int DP[22][10010] = {0};
int m = 0;

int solve(int start, int target)
{
	if(start > m)
		return 0;
	if(DP[start][target] != 0)
		return DP[start][target];
	if(target == 0)
		return 0;
	int now = target;
	int result = 0;
	while(1)
	{
		if(now < 0)
			break;
		if(now == 0)
			result++;
		result = result + solve(start+1, now);
		now = now - input[start];
	}
	DP[start][target] = result;
	return result;
}

int compare (const void * a, const void * b)
{
	return ( *(int*)b - *(int*)a );
}

int main ()
{
	int n;
	cin >> n;
	for(int count=1; count<=n; count++)
	{
		m = 0;
		cin >> m;
		memset(input, 0, sizeof(input));
		memset(DP, 0, sizeof(DP));

		for(int i=1; i<=m; i++)
		{
			cin >> input[i];
		}
	  	qsort (input+1, m, sizeof(int), compare);

		int target = 0;
		cin >> target;
		solve(1,target);
		cout << DP[1][target] << endl;
	}
}
