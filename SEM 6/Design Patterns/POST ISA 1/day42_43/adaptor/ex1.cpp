#include <iostream>
using namespace std;
#include <vector>
// 1. implement Stack by inheriting from vector
// Wrong implementation
// Stack cannot support every interface of vector
class Stack : public vector<int>
{
	
};

int main()
{
	Stack s;
	// do not like this interface; not words in stack
	s.push_back(10);
	s.push_back(20);
	cout << s.back() << "\n";
	s.pop_back();
	cout << s.back() << "\n";
	s.pop_back();
	
	// breaks the stack property
	vector<int> *pv(&s);
	pv->insert(begin(*pv), 100);
	pv->insert(begin(*pv), 200);
	cout << s.back() << "\n"; // 100
	
	
}

