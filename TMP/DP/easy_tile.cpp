#include<iostream>
#include<vector>

int main ()
{
	int n;
	std::cin >> n;
	std::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	
	for(int i=3; i<=n; i++)		
	{
		v.push_back( (v.at(i-1) + v.at(i-2)) % 10007 );
	}
	std::cout << v.at(n);
}