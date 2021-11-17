#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <queue>

int main()
{
	{
		queue<int> q; // queue<int, deque<int>> q;
		q.push(10);
		q.push(20);
		cout << q.front() << "\n";
		q.pop();
		cout << q.front() << "\n";
		q.pop();
	}
	{
		queue<int, list<int>> q; // queue<int, list<int>> q;
		q.push(10);
		q.push(20);
		cout << q.front() << "\n";
		q.pop();
		cout << q.front() << "\n";
		q.pop();
	}
	{
		// NO
		queue<int, vector<int>> q; // queue<int, vector<int>> q;
		q.push(10);
		q.push(20);
		cout << q.front() << "\n";
		//q.pop(); // vector does not support pop_front
	}
}
