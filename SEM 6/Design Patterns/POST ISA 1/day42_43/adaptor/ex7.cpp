#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <memory>
#include <algorithm>

int add(int x, int y)
{
	int res = x + y;
	cout << res << "\n";
	return res;
}
int main()
{
	vector<int> v{11, 22, 33, 44, 55};
	// add 100 to each element
	for(int e : v)
	{
		cout << add(e, 100) << "\n";
	}
	// last arg : should be a callable which takes one argument
	
	// modifies interface; change a fn which takes two args to fn which takes
	//	no arguments
	auto f1 = bind(add, 10, 20);
	cout << f1() << "\n";
	auto f2 = bind(add, 100, placeholders::_1);
	for_each(begin(v), end(v), f2 );
}
