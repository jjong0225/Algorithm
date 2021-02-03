#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
	stack<int> S;
	char command[30];
	int counter;
	cin >> counter;
	for (int i = 0; i < counter; i++)
	{
		cin >> command;
		if (!strcmp(command, "push")) {
			int next;
			cin >> next;
			S.push(next);
		}
		else if (!strcmp(command, "pop")) {
			if (S.empty())
				cout << -1 << endl;
			else {
				cout << S.top() << endl;
				S.pop();
			}
		}
		else if (!strcmp(command, "size")) {
			cout << S.size() << endl;
		}
		else if (!strcmp(command, "empty")) {
			cout << S.empty() << endl;
		}
		else if (!strcmp(command, "top")) {
			if (S.empty())
				cout << -1 << endl;
			else {
				cout << S.top() << endl;
			}
		}
		else
			i--;
	}
	return 0;
}
